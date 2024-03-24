#include<stdio.h>

// Function prototypes
int prime(int);
void readfromfile(char* filename, int *n);
void writetofile(char* filename, char *result);

int main() {
    int n;

    // Read an integer from the input file
    readfromfile("input.txt", &n);

    // Check if the number is prime
    prime(n);

    return 0;
}

// Function to check if a number is prime
int prime(int n) {
    int i, flag = 1;

    // Loop to check for factors of n
    for(i = 2; i < n; i++) {
        if(n % i == 0) {
            flag = 0;
            break;
        }
    }

    // Declare a character array to store result
    char result[50];

    // Write the result to the result string
    if(flag == 1) {
        sprintf(result, "\nThe given number is a prime number");
    } else {
        sprintf(result, "\nThe given number is not a prime number");
    }

    // Write the result to the output file
    writetofile("output.txt", result);
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

    // Close the file
    fclose(file);
}

// Function to write a string to a file
void writetofile(char* filename, char *result) {
    FILE *file = fopen(filename, "w");

    // Check if the file opened successfully
    if(file == NULL) {
        printf("Error opening output file %s", filename);
        return;
    }

    // Write the result to the file
    fprintf(file, "%s\n", result);

    // Close the file
    fclose(file);

    // Print a message indicating successful write
    printf("\nResults are written to %s\n", filename);
}
