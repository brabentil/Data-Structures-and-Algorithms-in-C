// This program sorts an array of integers in ascending order using bubble sort algorithm.
// User inputs the number of elements to be sorted and the elements themselves.
// The program displays the original array and the sorted array, as well as the number of swaps made during sorting.

#include <stdio.h>

int main() {
    int a[15], i, n, j, temp, c = 0;

    // Ask user for the number of elements to be sorted
    printf("Please enter the number of elements (maximum 15): ");
    scanf("%d", &n);

    // Ask user to enter the elements to be sorted
    printf("Please enter the %d numbers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        getchar(); // consume the newline character
    }

    // Display the numbers entered by the user
    printf("You entered the following numbers: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Wait for user to press any key before continuing
    printf("\n Press any key to continue:");
    getchar();

    // Sort the array using bubble sort algorithm
    for(i = 1; i < n-1; i++)
    {
        for(j = 0; j < n; j++) {
            if(a[j] > a[j+1]) {
                // Swap the two elements if they are in the wrong order
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                c++; // Increment the swap counter
            }
        }
    }

    // Display the sorted array and the number of swaps made during sorting
    for (i=0; i<n; i++)
    {
        printf("\n The elements of :a[%d]:%d", i, a[i]);
        getchar();
    }
    printf("The value of c is : %d", c);

    return 0;
}
