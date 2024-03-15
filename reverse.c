#include <stdio.h>

int reverseNumber(int n) {
    int reverse = 0;
    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}

int main() {
    int number, reversedNumber;

    // Input number from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Reverse the number
    reversedNumber = reverseNumber(number);

    // Display the result
    printf("Reversed number: %d\n", reversedNumber);

    return 0;
}
