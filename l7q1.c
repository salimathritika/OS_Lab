#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 5

sem_t empty, full;
pthread_mutex_t mutex;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int produced_count = 0, consumed_count = 0;

void *producer(void *arg) {
    int item = 0;
    while (produced_count < MAX_ITEMS) {
        item++;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        produced_count++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *arg) {
    int item;
    while (consumed_count < MAX_ITEMS) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        consumed_count++;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

