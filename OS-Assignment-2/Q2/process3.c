#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>

int main() {
    
    struct sched_param param;
    param.sched_priority = 50;
    int result = sched_setscheduler(0, SCHED_FIFO, &param);
    if (result == -1) {
        perror("sched_setscheduler");
        exit(1);
    }
    else {
        execl("./count", "./count", NULL);
    }

    return 0;
}