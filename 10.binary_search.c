#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int size, target;

    // Input the size of the array
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &size);

    int arr[size];
    
    // Input elements of the array
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target value to search for
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Output the result
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
