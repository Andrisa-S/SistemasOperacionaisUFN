#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t filho1, filho2;
    int i;

    // Cria o primeiro processo filho
    filho1 = fork();
    if (filho1 < 0) {
        perror("Erro ao criar filho1");
        exit(1);
    }

    if (filho1 == 0) {
        // Código executado pelo filho1
        for (i = 100; i <= 200; i++) {
            printf("Filho1 (PID %d): %d\n", getpid(), i);
            sleep(1); // intervalo de 1 segundo
        }
        printf("Filho1 finalizou\n");
        exit(0);
    }

    // Cria o segundo processo filho
    filho2 = fork();
    if (filho2 < 0) {
        perror("Erro ao criar filho2");
        exit(1);
    }

    if (filho2 == 0) {
        // Código executado pelo filho2
        for (i = 250; i <= 350; i++) {
            printf("Filho2 (PID %d): %d\n", getpid(), i);
            sleep(1); // intervalo de 1 segundo
        }
        printf("Filho2 finalizou\n");
        exit(0);
    }

    // Código executado pelo processo pai
    for (i = 1; i <= 50; i++) {
        printf("Pai (PID %d): %d\n", getpid(), i);
        sleep(2); // intervalo de 2 segundos
    }
    printf("Processo Pai finalizou\n");

    // Pai aguarda a conclusão dos dois filhos
    waitpid(filho1, NULL, 0);
    waitpid(filho2, NULL, 0);

    return 0;
}