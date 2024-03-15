#include <stdio.h>

void Fibonacci_series(int last) {
    int a = 0, b = 1, next = 0;

    printf("Fibonacci Series up to %d:\n", last);
    printf("%d, %d, ", a, b);
    next = a + b;

    while (next <= last) {
        printf("%d, ", next);
        a = b;
        b = next;
        next = a + b;
    }
}

int main() {
    int last;

    printf("Enter the limit for Fibonacci Series: ");
    scanf("%d", &last);

    Fibonacci_series(last);

    return 0;
}
