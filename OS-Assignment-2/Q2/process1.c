#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>

int main() {
    
    struct sched_param param;
    param.sched_priority = 0;
    int result = sched_setscheduler(0, SCHED_OTHER, &param);
    if (result == -1) {
        perror("sched_setscheduler");
        exit(1);
    }
    else {
        execl("./count", "./count", NULL);
    }

    return 0;
}