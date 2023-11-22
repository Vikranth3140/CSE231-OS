#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t bridge;
sem_t left_queue;
sem_t right_queue;
sem_t opposite_dir;
sem_t left_mutex;
sem_t right_mutex;
sem_t queue_barrier;

int left_cars;
int right_cars;

#define MAX_CARS_AT_ONCE 5

void* left(void* args) {
    for (int i = 1; i <= left_cars; ++i) {
        sem_wait(&left_queue);
        sem_wait(&left_mutex);
        sem_wait(&opposite_dir);
        sem_post(&left_queue);
        sem_post(&left_mutex);

        sem_wait(&queue_barrier);

        sem_wait(&bridge);

        passing(0, i);

        sem_post(&bridge);
        sem_wait(&left_mutex);
        sem_post(&opposite_dir);
        sem_post(&left_mutex);

        sem_post(&queue_barrier);
    }
    return NULL;
}

void* right(void* args) {
    for (int i = 1; i <= right_cars; ++i) {
        sem_wait(&right_queue);
        sem_wait(&right_mutex);
        sem_wait(&opposite_dir);
        sem_post(&right_queue);
        sem_post(&right_mutex);

        sem_wait(&queue_barrier);

        sem_wait(&bridge);

        passing(1, i);

        sem_post(&bridge);
        sem_wait(&right_mutex);
        sem_post(&opposite_dir);
        sem_post(&right_mutex);

        sem_post(&queue_barrier);
    }
    return NULL;
}

void passing(int dir, int car_number) {
    printf("Car %d from %s side is crossing the bridge.\n", car_number, (dir == 0) ? "left" : "right");
    sleep(1);
    printf("Car %d from %s side has crossed the bridge.\n", car_number, (dir == 0) ? "left" : "right");
}

int main() {
    sem_init(&bridge, 0, MAX_CARS_AT_ONCE);
    sem_init(&left_queue, 0, 1);
    sem_init(&right_queue, 0, 1);
    sem_init(&opposite_dir, 0, 1);
    sem_init(&left_mutex, 0, 1);
    sem_init(&right_mutex, 0, 1);
    sem_init(&queue_barrier, 0, MAX_CARS_AT_ONCE);

    printf("Enter the number of cars on the left: ");
    scanf("%d", &left_cars);

    printf("Enter the number of cars on the right: ");
    scanf("%d", &right_cars);

    pthread_t left_thread, right_thread;
    pthread_create(&left_thread, NULL, left, NULL);
    pthread_create(&right_thread, NULL, right, NULL);

    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    sem_destroy(&bridge);
    sem_destroy(&left_queue);
    sem_destroy(&right_queue);
    sem_destroy(&opposite_dir);
    sem_destroy(&left_mutex);
    sem_destroy(&right_mutex);
    sem_destroy(&queue_barrier);

    return 0;
}