#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[] = {50, 60, 10, 30};
    int n = 4;
    int i;

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    bubbleSort(A, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
