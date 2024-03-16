#include <stdio.h>

int main() {
    int array[100], n, i;
    int largest, smallest;
    double sum = 0, average;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    largest = smallest = array[0];

    for (i = 1; i < n; i++) {
        if (array[i] > largest)
            largest = array[i];
        if (array[i] < smallest)
            smallest = array[i];
    }

    average = sum / n;

    printf("The largest element in the array is: %d\n", largest);
    printf("The smallest element in the array is: %d\n", smallest);
    printf("The sum of all elements in the array is: %.2f\n", sum);
    printf("The average of all elements in the array is: %.2f\n", average);

    return 0;
}
