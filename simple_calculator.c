8.Calculator
#include<stdio.h>

// Function prototypes
void calculator(float, float);
void readfromfile(char*, float*, float*);
void writetofile(char*, float);

int main() {
    // Declare variables for numbers
    float num1, num2;

    // Read numbers from file
    readfromfile("input.txt", &num1, &num2);

    // Perform calculations
    calculator(num1, num2);

    return 0;
}

// Function to perform calculations based on operator
void calculator(float num1, float num2) {
    char opp;
    float result;

    // Prompt user to enter operator
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &opp);

    // Perform operation based on operator
    switch(opp) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                result = -1; // Indicate division by zero
            } else {
                result = num1 / num2;
            }
            break;
        default:
            result = 0; // Default result if operator is invalid
            break;
    }

    // Write result to file
    writetofile("output.txt", result);
}

// Function to read numbers from file
void readfromfile(char* filename, float* num1, float* num2) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening input file");
        return;
    }
    fscanf(file, "%f%f", num1, num2); // Read numbers from file
    fclose(file);
}

// Function to write result to file
void writetofile(char* filename, float result) {
    FILE* file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error opening output file %s", filename);
        return;
    }
    fprintf(file, "%.2f\n", result); // Write result to file
    fclose(file);
    printf("\nResults are written to %s\n", filename);
}
