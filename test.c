#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If element is not present
    return -1;
}

int main() {
    int n, key;
    clock_t start, end;
    double cpu_time_used;
    // Ask user for size of array
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    // Fill array with sorted values (0, 1, 2, ..., n-1)
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    // Ask user for element to search
    printf("Enter element to search: ");
    scanf("%d", &key);
    // Start timer
    start = clock();
    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);
    // End timer
    end = clock();
    // Calculate execution time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // Print result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in array.\n");
    // Print execution time
    printf("Execution time: %f seconds\n", cpu_time_used);

    // Free allocated memory
    free(arr);
    return 0;
}
