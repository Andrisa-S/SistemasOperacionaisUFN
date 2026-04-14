#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

#define N 1000000
int v1[N], v2[N], resultado[N];
int num_threads;

void* soma(void* arg) {
    int id = *(int*)arg;
    int inicio = id * (N/num_threads);
    int fim = (id+1) * (N/num_threads);

    for(int i=inicio; i<fim; i++) {
        resultado[i] = v1[i] + v2[i];
    }
    return NULL;
}

int main() {
    for(int i=0; i<N; i++) {
        v1[i] = i;
        v2[i] = i;
    }

    printf("Digite número de threads: ");
    scanf("%d", &num_threads);

    pthread_t t[num_threads];
    int ids[num_threads];

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for(int i=0; i<num_threads; i++) {
        ids[i] = i;
        pthread_create(&t[i], NULL, soma, &ids[i]);
    }
    for(int i=0; i<num_threads; i++)
        pthread_join(t[i], NULL);

    gettimeofday(&fim, NULL);
    double tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec)/1000000.0;
    printf("Tempo de execução: %.6f segundos\n", tempo);

    return 0;
}
