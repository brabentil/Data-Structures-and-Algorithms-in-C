#include<stdio.h>
#include <conio.h>

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform insertion sort
void insertionSort() {
    int n, i, key, j;

    // Get the number of elements from the user
    printf("Enter the number of elements to be sorted:\n");
    scanf("%d", &n);

    int arr[n];

    // Get array elements from the user
    printf("\nEnter the elements\n\n");
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("Original array: ");
    printArray(arr, n);

    // Wait for user input before starting the sorting process
    printf("\nEnter any key to continue\n");
    getch();

    // Insertion sort algorithm
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Display the sorted array
    printf("Sorted array: ");
    printArray(arr, n);
}



