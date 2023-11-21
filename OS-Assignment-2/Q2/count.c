#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main() {

    uint64_t max_count = (1ULL << 32);
    for (uint64_t i = 1; i <= max_count; i++) {
        if (i % 1000000000 == 0) {
            printf("Process %d: Counted up to %lu\n", getpid(), i);
        }
    }
    return 0;
}