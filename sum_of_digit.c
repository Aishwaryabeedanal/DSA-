#include<stdio.h>

// Function prototypes
int sumofdigits(int);
void readfromfile(char*, int*);
void writetofile(char*, int);

int main() {
    int n;

    // Read an integer from the file
    readfromfile("input.txt", &n);

    // Calculate the sum of digits
    int sum = sumofdigits(n);

    // Write the result to the output file
    writetofile("output.txt", sum);

    return 0;
}

// Function to calculate the sum of digits of a number
int sumofdigits(int n) {
    int sum = 0, ld;

    // Loop to extract digits and calculate sum
    while(n != 0) {
        ld = n % 10;    // Extract the last digit
        sum += ld;      // Add the last digit to the sum
        n = n / 10;     // Remove the last digit
    }

    return sum;
}

// Function to read an integer from a file
void readfromfile(char* filename, int *n) {
    FILE *file = fopen(filename, "r");

    // Check if the file opened successfully
    if(file == NULL) {
        printf("Error opening input file");
        return;
    }

    // Read an integer from the file
    fscanf(file, "%d", n);

    // Close the input file
    fclose(file);
}

// Function to write an integer to a file
void writetofile(char* filename, int result) {
    FILE *file = fopen(filename, "w");

    // Check if the file opened successfully
    if(file == NULL) {
        printf("Error opening output file %s", filename);
        return;
    }

    // Write the result to the file
    fprintf(file, "Sum of digits = %d\n", result);

    // Close the output file
    fclose(file);

    // Print a message indicating successful write
    printf("\nResult is written to %s\n", filename);
}

