#include <stdio.h>
int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    while (i < j) {
        while (A[i] <= pivot && i < h) {
            i++;
        }
        
        while (A[j] > pivot && j > l) {
            j--;
        }
        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    
    int temp = A[l];
    A[l] = A[j];
    A[j] = temp;

    return j;
}


void quickSort(int A[], int l, int h) {
    if (l < h) {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}


void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    quickSort(A, 0, n - 1);

    printf("Sorted array:   ");
    printArray(A, n);
    
    return 0;
}