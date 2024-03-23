#include <stdio.h>
#include <string.h>

int main() {
    // Define two strings
    char str1[50] = "Hello";
    char str2[50] = "World";

    // Concatenation: Concatenate str2 at the end of str1
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Copying: Copy str1 to str3
    char str3[50];
    strcpy(str3, str1);
    printf("Copied string: %s\n", str3);

    // Comparison: Compare str1 and str2
    int cmp = strcmp(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal\n");
    }
    else{
        printf("Strings are not equal\n");
    }

    return 0;
}
