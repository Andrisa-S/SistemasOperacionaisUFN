#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <time.h>

#define TAMANHO 10000
#define MAX_PROCESSOS 8

void preencher_vetores(int *v1, int *v2, int n) {
    srand(12345);
    for (int i = 0; i < n; i++) {
        v1[i] = rand() % 100;
        v2[i] = rand() % 100;
    }
}

int main() {
    // Cria memória compartilhada anônima para os três vetores
    int *vetor1 = mmap(NULL, TAMANHO * sizeof(int), PROT_READ | PROT_WRITE,
                       MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int *vetor2 = mmap(NULL, TAMANHO * sizeof(int), PROT_READ | PROT_WRITE,
                       MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int *resultado = mmap(NULL, TAMANHO * sizeof(int), PROT_READ | PROT_WRITE,
                          MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (vetor1 == MAP_FAILED || vetor2 == MAP_FAILED || resultado == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    preencher_vetores(vetor1, vetor2, TAMANHO);

    printf("Quantidade de processos | Tempo (segundos, microssegundos)\n");
    printf("----------------------------------------------------------\n");

    for (int num_proc = 1; num_proc <= MAX_PROCESSOS; num_proc++) {
        struct timeval tpI, tpF;
        gettimeofday(&tpI, NULL);

        int intervalo = TAMANHO / num_proc;
        int resto = TAMANHO % num_proc;

        for (int i = 0; i < num_proc; i++) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("fork");
                exit(1);
            }
            if (pid == 0) {
                int inicio = i * intervalo;
                int fim = (i == num_proc - 1) ? TAMANHO : inicio + intervalo;
                if (i == num_proc - 1) fim = TAMANHO; // garante resto

                for (int j = inicio; j < fim; j++) {
                    resultado[j] = vetor1[j] + vetor2[j];
                }
                exit(0);
            }
        }

        for (int i = 0; i < num_proc; i++) {
            wait(NULL);
        }

        gettimeofday(&tpF, NULL);

        int sec = tpF.tv_sec - tpI.tv_sec;
        int usec = tpF.tv_usec - tpI.tv_usec;
        if (usec < 0) {
            usec += 1000000;
            sec -= 1;
        }

        printf("%-20d | %d s %6d us\n", num_proc, sec, usec);

        // Verifica resultado apenas para o primeiro teste
        if (num_proc == 1) {
            int ok = 1;
            for (int i = 0; i < TAMANHO; i++) {
                if (resultado[i] != vetor1[i] + vetor2[i]) {
                    ok = 0;
                    break;
                }
            }
            printf("Resultado verificado: %s\n", ok ? "correto" : "incorreto");
        }
    }

    munmap(vetor1, TAMANHO * sizeof(int));
    munmap(vetor2, TAMANHO * sizeof(int));
    munmap(resultado, TAMANHO * sizeof(int));

    return 0;
}