#include <string.h>
#include <stdio.h>
#include <conio.h>

void swap(char **arr1, char **arr2) {
    char *temp;

    temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
void bubbleSort()
{
    int n,i,j;



    printf("Enter the number of elements to be sorted: \n");
    scanf("%d", &n);

    char stringarr[n][20];

    printf("Enter the elements: \n");

    for ( i = 0; i < n; i++) {
        printf("Enter element %d: \n", i + 1);
        scanf(" %s", &stringarr[i]);




    }
    printf("The elements entered are:\n");
    for( i = 0; i < n; i++) {
        printf("Element %d: %s\n", i+1, stringarr[i]);
    }

    printf("\nPress any key to continue\n");
    getch();

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(stringarr[j], stringarr[j + 1]) > 0) {
                swap(&stringarr[j],  &stringarr[j + 1]);
            }
        }
    }
    printf("The elements after sorting:\n");
    for( i = 0; i < n; i++) {
        printf("Element %d: %s\n", i+1, stringarr[i]);
    }

}
