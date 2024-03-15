#include <stdio.h>

int main() {
    int num, n1, n2;

    printf("Enter a two-digit number: ");
    scanf("%d", &num);


    n1 = num / 10;
    n2 = num % 10;
    int sum =n1 + n2;


    printf("Sum of digits of %d is %d.\n", num, sum);

    return 0;
}
