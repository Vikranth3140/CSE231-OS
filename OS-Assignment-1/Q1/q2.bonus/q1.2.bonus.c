#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int rc = fork();
    if (rc < 0) {
        perror("fork failed");
        exit(1);
    } else if (rc == 0) {
        wait(NULL);
        char *p1_args[] = {"./p1", NULL};
        execvp(p1_args[0], p1_args);
        perror("execvp");
        exit(1);
    } else {
        char *p2_args[] = {"./p2", NULL};
        execvp(p2_args[0], p2_args);
        perror("execvp p2");
        exit(1);
    }
    return 0;
}