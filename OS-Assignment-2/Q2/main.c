#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>
#include <time.h>

int main() {
    pid_t pids[3];
    struct timespec start_time, end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    pids[0] = fork();
    if (pids[0] == -1) {
        perror("fork");
        exit(1);
    }
    else if (pids[0] == 0) {
        execl("./process1", "./process1", NULL);
        perror("execl");
        exit(1);
    }
    else {
        waitpid(pids[0], NULL, 0);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        double execution_time_other = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
        printf("Execution time (SCHED_OTHER): %.6f seconds\n", execution_time_other);
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    pids[1] = fork();
    if (pids[1] == -1) {
        perror("fork");
        exit(1);
    }
    else if (pids[1] == 0) {
        execl("./process2", "./process2", NULL);
        perror("execl");
        exit(1);
    }
    else {
        waitpid(pids[1], NULL, 0);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        double execution_time_rr = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
        printf("Execution time (SCHED_RR): %.6f seconds\n", execution_time_rr);
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    pids[2] = fork();
    if (pids[2] == -1) {
        perror("fork");
        exit(1);
    }
    else if (pids[2] == 0) {
        execl("./process3", "./process3", NULL);
        perror("execl");
        exit(1);
    }
    else {
    waitpid(pids[2], NULL, 0);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time_fifo = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    printf("Execution time (SCHED_FIFO): %.6f seconds\n", execution_time_fifo);
    }

    return 0;
}