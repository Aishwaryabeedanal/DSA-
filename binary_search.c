#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid; // Return the index if element is found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int arr[] = {20, 30, 10, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int temp;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {

            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    // Perform binary search
    int index = binarySearch(arr, n, key);

    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}
