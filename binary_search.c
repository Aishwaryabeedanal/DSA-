#include<stdio.h>

// Function prototypes
int binarysearch(int n, int nu[]);
int readfromfile(char*, int[]);
void writetofile(char*, int);
void readarray(int[], int n, FILE*);
void printarray(int[], int n, FILE*);

int main() {
    int n, search;

    // Read the number of elements from the input file
    n = readfromfile("input.txt", NULL);

    // Check if reading from file failed
    if (n == 0) {
        printf("Unable to read data from file\n");
        return 1;
    }

    // Declare an array to store the elements
    int nu[n];

    // Read the elements from the file into the array
    if (readfromfile("input.txt", nu) != n) {
        printf("Unable to read data from file\n");
        return 1;
    }

    // Perform binary search
    search = binarysearch(n, nu);

    // Write search result to output file
    writetofile("output.txt", search);

    return 0;
}

// Function to read array from file
int readfromfile(char* filename, int nu[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening input file");
        return 0;
    }
    int n;
    fscanf(file, "%d", &n); // Read the number of elements
    if (nu == NULL) {
        fclose(file);
        return n;
    }
    int i = 0;
    while (fscanf(file, "%d", &nu[i]) != EOF) { // Read elements until EOF
        i++;
    }
    fclose(file);
    return i; // Return the number of elements read
}

// Function to perform binary search
int binarysearch(int n, int nu[]) {
    int low = 0, high = n - 1, mid, key;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);
    while (low <= high) {
        mid = (low + high) / 2;
        if (nu[mid] == key) {
            return mid; // Return index if key is found
        } else if (nu[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to write search result to file
void writetofile(char* filename, int search) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening input file");
        return;
    }
    if (search != -1) {
        fprintf(file, "Key element is found at index: %d\n", search); // Write if key is found
    } else {
        fprintf(file, "Key element not found\n"); // Write if key is not found
    }
    fclose(file);
    printf("\nSearch result is written to %s\n", filename);
}

