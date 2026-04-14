#include <stdio.h>
#include <pthread.h>

double largura, comprimento;

void* calcula_area(void* arg) {
    double area = largura * comprimento;
    printf("Área: %.2f\n", area);
    return NULL;
}

void* calcula_perimetro(void* arg) {
    double perimetro = 2 * (largura + comprimento);
    printf("Perímetro: %.2f\n", perimetro);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    printf("Digite largura e comprimento: ");
    scanf("%lf %lf", &largura, &comprimento);

    pthread_create(&t1, NULL, calcula_area, NULL);
    pthread_create(&t2, NULL, calcula_perimetro, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
