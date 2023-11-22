#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

#define PHILOSOPHERS 5
#define BOWLS 2

sem_t forks[PHILOSOPHERS];
sem_t bowls;

int left(int p) {
    return p;
}

int right(int p) { 
    return (p + 1) % PHILOSOPHERS;
}

void get_forks_and_bowl(int p) {
    if (p == 4) {
        sem_wait(&forks[right(p)]);
        sem_wait(&forks[left(p)]);
    } else {
        sem_wait(&forks[left(p)]);
        sem_wait(&forks[right(p)]);
    }
    sem_wait(&bowls); 
}

void put_forks_and_bowl(int p) {
    sem_post(&forks[left(p)]);
    sem_post(&forks[right(p)]);
    sem_post(&bowls); 
}

void* philosopher(void* args) {
    int philosopher_id = *((int*)args);

    while (1) {
        printf("Philosopher %d is thinking\n", philosopher_id);
        sleep(1);

        get_forks_and_bowl(philosopher_id);

        printf("Philosopher %d is eating\n", philosopher_id);
        sleep(1);

        put_forks_and_bowl(philosopher_id);
    }

    return NULL;
}

int main() {
    pthread_t philosophers[PHILOSOPHERS];
    int philosopher_ids[PHILOSOPHERS];

    for (int i = 0; i < PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    sem_init(&bowls, 0, BOWLS);

    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    for (int i = 0; i < PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }

    sem_destroy(&bowls);

    return 0;
}