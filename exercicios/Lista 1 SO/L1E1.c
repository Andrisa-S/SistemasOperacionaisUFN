#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    float comprimento, largura;
    int pid;

    // Entrada dos dados (feita uma vez, antes do fork)
    printf("Digite o comprimento do terreno (m): ");
    scanf("%f", &comprimento);
    printf("Digite a largura do terreno (m): ");
    scanf("%f", &largura);

    // Cria o processo filho
    pid = fork();

    if (pid < 0) { // erro
        perror("Erro no fork");
        exit(1);
    }
    else if (pid == 0) {
        // --- CÓDIGO DO FILHO ---
        float area = comprimento * largura;
        printf("FILHO: Área do terreno = %.2f m²\n", area);
        exit(0); // encerra o filho
    }
    else {
        // --- CÓDIGO DO PAI ---
        float perimetro = 2 * (comprimento + largura);
        printf("PAI: Perímetro do terreno = %.2f m\n", perimetro);

        // Aguarda o filho terminar
        wait(NULL); // NULL porque não nos interessa o status de saída
    }

    return 0;
}