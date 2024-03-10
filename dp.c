#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];

int left_fork(int philosopher_id) {
    return philosopher_id;
}

int right_fork(int philosopher_id) {
    return (philosopher_id + 1) % NUM_PHILOSOPHERS;
}

void *philosopher(void *arg) {
    int id = *((int *)arg);
    int first_fork, second_fork;

    // Assign forks based on philosopher id
    if (id % 2 == 0) {
        first_fork = left_fork(id);
        second_fork = right_fork(id);
    } else {
        first_fork = right_fork(id);
        second_fork = left_fork(id);
    }

    while (1) {
        // Try to pick up first fork
        pthread_mutex_lock(&forks[first_fork]);
        printf("Philosopher %d picked up fork %d\n", id, first_fork);

        // Try to pick up second fork
        pthread_mutex_lock(&forks[second_fork]);
        printf("Philosopher %d picked up fork %d\n", id, second_fork);

        // Eat
        printf("Philosopher %d is eating\n", id);

        // Release forks
        pthread_mutex_unlock(&forks[first_fork]);
        pthread_mutex_unlock(&forks[second_fork]);

        // Think
        printf("Philosopher %d is thinking\n", id);

        // Sleep for random time
        usleep(rand() % 1000000);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    // Initialize mutex locks for each fork
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create threads for philosophers
    pthread_t philosophers[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, philosopher, id);
    }

    // Join threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutex locks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}

