#include <stdio.h>
#define MAX 100 
int temp[MAX];

void merge(int A[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= h) {
        if (A[i] <= A[j]) {
            temp[k] = A[i];
            i++;
        } else {
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    
    if (i > mid) {
        while (j <= h) {
            temp[k] = A[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            temp[k] = A[i];
            i++;
            k++;
        }
    }

    for (k = l; k <= h; k++) {
        A[k] = temp[k];
    }
}

void mergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergeSort(A, l, mid);     
        mergeSort(A, mid + 1, h); 
        merge(A, l, mid, h);    
    }
}


void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {64, 25, 12, 22, 11, 90, 45};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    printArray(A, n);

    mergeSort(A, 0, n - 1);

    printf("Sorted array:\n");
    printArray(A, n);

    return 0;
}
