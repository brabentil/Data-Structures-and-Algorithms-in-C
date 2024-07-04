
void merge(int L[], int nL, int R[], int nR, int A[]) {
    int i = 0, j = 0, k = 0;

    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            k++;
            i++;
        } else {
            A[k] = R[j];
            k++;
            j++;
        }
    }

    // Adding Remaining elements from left sub array to array A
    while (i < nL) {
        A[k] = L[i];
        k++;
        i++;
    }

    // Adding Remaining elements from right sub array to array A
    while (j < nR) {
        A[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int A[], int n) {
    if (n <= 1) {
        return;
    }

    int mid = n / 2;
    int L[mid], R[n - mid];

    for (int i = 0; i < mid; i++) {
        L[i] = A[i];
    }

    for (int i = mid; i < n; i++) {
        R[i - mid] = A[i];
    }

    mergeSort(L, mid);
    mergeSort(R, n - mid);
    merge(L, mid, R, n - mid, A);
}
