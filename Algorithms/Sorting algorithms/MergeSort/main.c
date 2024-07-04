#include <stdio.h>

void merge(int L[], int nL, int R[], int nR, int A[]);

void mergeSort(int A[], int n) ;

int main() {
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);

    int arr[n];


    mergeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
