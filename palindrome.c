#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindromeString(char *str) {
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    // Check characters from start and end, moving towards the middle
    while (start < end) {
        if (str[start] != str[end]) {
            return false; // If characters don't match, it's not a palindrome
        }
        start++;
        end--;
    }
    return true; // If the loop completes, the string is a palindrome
}

int main() {
    char str[100];
    
    // Input string from the user
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Check if the string is a palindrome
    if (isPalindromeString(str)) {
        printf("%s is a palindrome string.\n", str);
    } else {
        printf("%s is not a palindrome string.\n", str);
    }
    
    return 0;
}
