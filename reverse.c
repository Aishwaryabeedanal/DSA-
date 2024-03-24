#include<stdio.h>

// Function prototypes
int reverse(int);
void readfromfile(char*, int*);
void writetofile(char*, int);

int main() {
    int n;

    // Read an integer from file
    readfromfile("input.txt", &n);

    // Calculate the reverse of the number
    int reversed = reverse(n);

    // Write the reversed number to the output file
    writetofile("output.txt", reversed);

    return 0;
}

// Function to reverse a given number
int reverse(int n) {
    int ld, rev = 0;

    // Loop to reverse the number
    while(n != 0) {
        ld = n % 10;    // Extract the last digit
        rev = rev * 10 + ld;    // Append the digit to the reversed number
        n = n / 10;    // Remove the last digit from the original number
    }

    // Return the reversed number
    return rev;
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

    // Write the reversed number to the file
    fprintf(file, "Reverse number = %d\n", result);

    // Close the output file
    fclose(file);

    // Print message indicating successful write
    printf("\nResults are written to %s\n", filename);
}
