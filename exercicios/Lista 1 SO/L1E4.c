#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid_filho1;

    // Pai cria o Filho 1
    pid_filho1 = fork();
    if (pid_filho1 < 0) {
        perror("Erro ao criar Filho 1");
        exit(1);
    }

    if (pid_filho1 == 0) {
        // --- Processo Filho 1 ---
        printf("Filho 1 (PID %d): Meu pai é %d\n", getpid(), getppid());

        // Filho 1 cria os filhos 2, 3, 4, 5
        for (int i = 2; i <= 5; i++) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("Erro ao criar filho");
                exit(1);
            }
            if (pid == 0) {
                // Código executado por cada filho (2 a 5)
                printf("Filho %d (PID %d): Meu pai é %d\n", i, getpid(), getppid());
                // Pequena pausa para tornar a saída mais legível (opcional)
                sleep(1);
                exit(0);
            }
        }

        // Filho 1 espera todos os seus filhos (2 a 5) terminarem
        for (int i = 2; i <= 5; i++) {
            wait(NULL);
        }
        printf("Filho 1 (PID %d) finalizou.\n", getpid());
        exit(0);
    } else {
        // --- Processo Pai ---
        printf("Pai (PID %d): Meu filho 1 é %d\n", getpid(), pid_filho1);
        // Pai espera o Filho 1 terminar
        wait(NULL);
        printf("Pai (PID %d) finalizou.\n", getpid());
    }

    return 0;
}