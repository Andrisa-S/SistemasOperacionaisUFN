#include <stdio.h>
#include <pthread.h>

int N;
int contador = 0;

void* incrementa(void* arg) {
    for(int i=0; i<N; i++) {
        contador++; // sem sincronização
    }
    return NULL;
}

int main() {
    pthread_t t[5]; // exemplo com 5 threads

    printf("Digite N: ");
    scanf("%d", &N);

    for(int i=0; i<5; i++)
        pthread_create(&t[i], NULL, incrementa, NULL);

    for(int i=0; i<5; i++)
        pthread_join(t[i], NULL);

    printf("Valor final: %d\n", contador);
    return 0;
}
