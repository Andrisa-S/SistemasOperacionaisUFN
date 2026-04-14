#include <stdio.h>
#include <pthread.h>

int N;

void* imprime(void* arg) {
    int id = *(int*)arg;
    for(int i=0; i<N; i++) {
        printf("Thread %d - interação %d\n", id, i);
    }
    return NULL;
}

int main() {
    pthread_t t[3];
    int ids[3] = {1,2,3};

    printf("Digite N: ");
    scanf("%d", &N);

    for(int i=0; i<3; i++)
        pthread_create(&t[i], NULL, imprime, &ids[i]);

    for(int i=0; i<3; i++)
        pthread_join(t[i], NULL);

    return 0;
}
