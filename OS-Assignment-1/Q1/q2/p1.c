#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main_factorial() {
    int num = 4;
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
    return 0;
}

int main() {
    main_factorial();
    return 0;
}