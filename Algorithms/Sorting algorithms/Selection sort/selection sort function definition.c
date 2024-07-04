#include <stdio.h>
#include <conio.h>

// Implementation of the selection sort algorithm
void selectionSort() {
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare an array to store the elements entered by the user
    int arr[n];

    // Get array elements from the user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the array before sorting
    printf("\nArray before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("Enter any key to continue:\n");
    getch();


    // Variables for the selection sort algorithm
    int i, j, index, temp;

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        index = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[index])
                index = j;
        }

        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    // Display the sorted array
    printf("\nArray after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
