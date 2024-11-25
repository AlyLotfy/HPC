#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>

#define num_threads 8

pthread_mutex_t mutex;
sem_t semaphore[num_threads];

void* thread_func(void* arg) {
    int thread_id = *(int*)arg;

    sem_wait(&semaphore[thread_id]); // Wait for semaphore signal

    pthread_mutex_lock(&mutex); // Enter critical section

    int random_number = rand() % 100; // Generate random number between 0 and 99
    printf("Thread %d generated number: %d\n", thread_id, random_number);

    pthread_mutex_unlock(&mutex); // Exit critical section

    if (thread_id + 1 < num_threads) {
        sem_post(&semaphore[thread_id + 1]); // Signal the next thread
    }

    return NULL;
}

int main() {
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize the semaphores
    for (int i = 0; i < num_threads; i++) {
        sem_init(&semaphore[i], 0, 0);
    }

    // Allow the first thread to start
    sem_post(&semaphore[0]);

    // Seed the random number generator
    srand(time(NULL));

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphores and mutex
    for (int i = 0; i < num_threads; i++) {
        sem_destroy(&semaphore[i]);
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}
