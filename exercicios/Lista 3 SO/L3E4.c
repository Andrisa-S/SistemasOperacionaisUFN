#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int vetor[5];
int count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* produtor(void* arg) {
    int valor = 1;
    while(1) {
        pthread_mutex_lock(&lock);
        if(count < 5) {
            vetor[count] = valor++;
            count++;
            printf("Produziu: %d (count=%d)\n", valor-1, count);
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void* consumidor(void* arg) {
    while(1) {
        pthread_mutex_lock(&lock);
        if(count > 0) {
            int removido = vetor[count-1];
            count--;
            printf("Consumiu: %d (count=%d)\n", removido, count);
        }
        pthread_mutex_unlock(&lock);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, produtor, NULL);
    pthread_create(&t2, NULL, consumidor, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
