#include <stdio.h>

void selectionsort(int arr[], int n) {
    // Traverse through all array elements
    for (int i = 0; i < n; i++) {
        // Find the minimum element in the unsorted portion of the array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update min_idx if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        if (min_idx != i) {
            int tmp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = tmp;
        }
    }
    return;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the array 
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Call the selection sort function to sort the array
    selectionsort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
