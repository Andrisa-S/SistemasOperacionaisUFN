#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 10   // Número de iterações de cada processo

int main() {
    pid_t pid1, pid2;
    int i;

    // Cria o primeiro processo filho
    pid1 = fork();

    if (pid1 < 0) {
        perror("Erro no primeiro fork");
        exit(1);
    }

    if (pid1 == 0) {
        // Código do primeiro filho
        for (i = 1; i <= N; i++) {
            printf("Filho 1 - Iteração %d\n", i);
            // Pequeno atraso para tornar a saída mais legível (opcional)
            usleep(10000); // 10 ms
        }
        exit(0);
    }

    // Cria o segundo processo filho
    pid2 = fork();

    if (pid2 < 0) {
        perror("Erro no segundo fork");
        exit(1);
    }

    if (pid2 == 0) {
        // Código do segundo filho
        for (i = 1; i <= N; i++) {
            printf("Filho 2 - Iteração %d\n", i);
            usleep(10000);
        }
        exit(0);
    }

    // Código do processo pai
    for (i = 1; i <= N; i++) {
        printf("Pai     - Iteração %d\n", i);
        usleep(10000);
    }

    // Pai espera os dois filhos terminarem
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("Todos os processos terminaram.\n");
    return 0;
}