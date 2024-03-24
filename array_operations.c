#include<stdio.h>

// Function prototypes
void readfromfile(char*, int[], int*);
void writetofile(char*, int, int, int, float);
void readarray(int[], int, FILE*);
void printarray(int[], int, FILE*);
int add(int[], int);
int largest(int[], int);
int smallest(int[], int);
float avg(int[], int);

int main() {
    int n, addition, maximum, minimum;
    float average;
    int nu[100];

    // Read data from file
    readfromfile("input.txt", nu, &n);

    // Calculate sum, largest, smallest, and average
    addition = add(nu, n);
    maximum = largest(nu, n);
    minimum = smallest(nu, n);
    average = avg(nu, n);

    // Write results to output file
    writetofile("output.txt", addition, maximum, minimum, average);

    return 0;
}

// Function to read data from file
void readfromfile(char* filename, int nu[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening input file");
        return;
    }
    fscanf(file, "%d", n); // Read the number of elements
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &nu[i]); // Read the elements
    }
    fclose(file);
}

// Function to write results to file
void writetofile(char* filename, int addition, int maximum, int minimum, float average) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening output file");
        return;
    }
    // Write the results to the file
    fprintf(file, "Sum of the numbers = %d\n", addition);
    fprintf(file, "Largest number = %d\n", maximum);
    fprintf(file, "Smallest number = %d\n", minimum);
    fprintf(file, "Average of the numbers = %.2f\n", average);
    fclose(file);
}

// Function to read array from file
void readarray(int nu[], int n, FILE *file) {
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &nu[i]);
    }
}

// Function to print array values
void printarray(int nu[], int n, FILE *file) {
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", nu[i]);
    }
}

// Function to calculate sum of elements
int add(int nu[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nu[i];
    }
    return sum;
}

// Function to find the largest element
int largest(int nu[], int n) {
    int max = nu[0];
    for (int i = 1; i < n; i++) {
        if (nu[i] > max) {
            max = nu[i];
        }
    }
    return max;
}

// Function to find the smallest element
int smallest(int nu[], int n) {
    int min = nu[0];
    for (int i = 1; i < n; i++) {
        if (nu[i] < min) {
            min = nu[i];
        }
    }
    return min;
}

// Function to calculate the average
float avg(int nu[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nu[i];
    }
    return sum / n;
}
