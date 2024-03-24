#include<stdio.h>

// Function prototypes
int palindrome(int);
void readfromfile(char*, int*);
void writetofile(char*, char*);

int main() {
    int n;

    // Read an integer from file
    readfromfile("input.txt", &n);

    // Check if the number is a palindrome
    palindrome(n);

    return 0;
}

// Function to check if a number is palindrome
int palindrome(int n) {
    int ld, i, rev = 0, palin = n;

    // Reverse the number
    while(n != 0) {
        ld = n % 10;
        rev = rev * 10 + ld;
        n = n / 10;
    }

    char result[50];

    // Check if the original number is equal to its reverse
    if(rev == palin) {
        sprintf(result, "\n%d is a palindrome number", palin);
    } else {
        sprintf(result, "\n%d is not a palindrome number", palin);
    }

    // Write the result to file
    writetofile("output.txt", result);
}

// Function to read an integer from file
void readfromfile(char* filename, int *n) {
    FILE *file = fopen(filename, "r");

    // Check if file opened successfully
    if(file == NULL) {
        printf("Error opening input file");
        return;
    }

    // Read integer from file
    fscanf(file, "%d", n);

    // Close the input file
    fclose(file);
}

// Function to write a string to file
void writetofile(char* filename, char *result) {
    FILE *file = fopen(filename, "w");

    // Check if file opened successfully
    if(file == NULL) {
        printf("Error opening output file %s", filename);
        return;
    }

    // Write string to file
    fprintf(file, "%s\n", result);

    // Close the output file
    fclose(file);

    // Print message indicating successful write
    printf("\nResults are written to %s\n", filename);
}
