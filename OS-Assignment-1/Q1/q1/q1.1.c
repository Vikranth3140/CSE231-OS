#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv []) {
    printf ("A) Parent (P) is having ID <%d>\n", (int) getpid ());
    int rc = fork ();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("c) Child is having ID <%d>\n", (int) getpid());
        printf("D) My Parent ID is <%d>\n", (int) getppid());
    } else {
        int wc = wait(NULL);
        printf("B) ID of P's Child is <%d>\n", rc);
    }
    return 0;
}