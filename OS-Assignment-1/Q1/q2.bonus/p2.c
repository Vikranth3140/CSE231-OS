#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void print_fibonacci_sequence(int n, int current) {
    if (current >= n) {
        return;
    }
    printf("%d ", fibonacci(current));
    print_fibonacci_sequence(n, current + 1);
}

int main_fibonacci() {
    int n = 16;
    int fib = fibonacci(n);
    printf("The Fibonacci sequence is ");
    print_fibonacci_sequence(n, 0);
    printf("\n");
    return 0;
}

int main() {
    main_fibonacci();
    return 0;
}