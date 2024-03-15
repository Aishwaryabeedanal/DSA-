#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    // Handling special cases
    if (num <= 1) {
        return false; // 0 and 1 are not prime
    }
    if (num <= 3) {
        return true; // 2 and 3 are prime
    }

    // Check if num is divisible by any number from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // num is divisible by i, hence not prime
        }
    }

    return true; // If num is not divisible by any number from 2 to sqrt(num), it is prime
}

int main() {
    int number;

    // Input number from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is prime
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}
