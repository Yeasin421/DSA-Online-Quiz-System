#include <stdio.h>

void countingSort(int arr[], int n, int max) {
    int count[max+1], output[n];
    for(int i=0;i<=max;i++) count[i]=0;
    for(int i=0;i<n;i++) count[arr[i]]++;
    for(int i=1;i<=max;i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--) {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++) arr[i]=output[i];
}

int main() {
    int A[]={0,2,1,4,6,2,1,1,0,3,7,7,9};
    int n=13;
    int max=9;
    countingSort(A,n,max);
    for(int i=0;i<n;i++) printf("%d ",A[i]);
    return 0;
}
