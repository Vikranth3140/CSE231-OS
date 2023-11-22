#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_PASSENGERS 100

sem_t car_mutex;
sem_t board_queue, unboard_queue;

int total_passengers;
int car_capacity;
int passengers_on_board = 0;

void* car(void* args);
void* passenger(void* args);
void load();
void unload();
void board(int passenger_id);
void offboard(int passenger_id);

void* car(void* args) {
    while (1) {
        load();

        for (int i = 0; i < car_capacity; ++i) {
            sem_post(&board_queue);
        }

        for (int i = 0; i < car_capacity; ++i) {
            sem_wait(&unboard_queue);
        }

        unload();

        sleep(4);

        for (int i = 0; i < car_capacity; ++i) {
            sem_post(&unboard_queue);
        }

        for (int i = 0; i < car_capacity; ++i) {
            sem_wait(&unboard_queue);
        }

    }

    return NULL;
}

void* passenger(void* args) {
    int passenger_id = (intptr_t)args;

    while (1) {
        sem_wait(&board_queue);

        board(passenger_id);

        if (++passengers_on_board == car_capacity) {
            printf("Car is full.\n");
        }

        sem_post(&unboard_queue);

        sem_wait(&unboard_queue);
        offboard(passenger_id);

        if (--passengers_on_board == 0) {
            printf("Car is empty.\n");
        }

        sem_post(&unboard_queue);
    }

    return NULL;
}

void load() {
    printf("Car is ready to load passengers.\n");
    sleep(1);
}

void unload() {
    printf("Ride over. Unloading passengers.\n");
    sleep(1);
}

void board(int passenger_id) {
    printf("Passenger %d is boarding the car.\n", passenger_id);
    sleep(1);
}

void offboard(int passenger_id) {
    printf("Passenger %d is getting off the car.\n", passenger_id);
    sleep(1);
}

int main() {
    
    printf("Enter the total number of passengers: ");
    scanf("%d", &total_passengers);

    while (total_passengers <= 0) {

        printf("Error: Must be greater than zero.\n");
        printf("Enter the total number of passengers: ");
        scanf("%d", &total_passengers);
        
    }

    printf("Enter the car capacity: ");
    scanf("%d", &car_capacity);

    sem_init(&car_mutex, 0, 1);
    sem_init(&board_queue, 0, 0);
    sem_init(&unboard_queue, 0, 0);

    pthread_t car_thread;
    pthread_create(&car_thread, NULL, car, NULL);

    pthread_t passenger_threads[MAX_PASSENGERS];
    for (int i = 1; i <= total_passengers; ++i) {
        pthread_create(&passenger_threads[i], NULL, passenger, (void*)(intptr_t)i);
    }

    pthread_join(car_thread, NULL);
    for (int i = 1; i <= total_passengers; ++i) {
        pthread_join(passenger_threads[i], NULL);
    }

    sem_destroy(&car_mutex);
    sem_destroy(&board_queue);
    sem_destroy(&unboard_queue);

    return 0;
}