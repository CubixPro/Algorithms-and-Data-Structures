#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10000

int arr[MAX_SIZE];
void merge(int, int, int);

void mergesort(int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high){
    int *A = (int *)malloc(sizeof(int) * (mid - low + 1));
    int *B = (int *)malloc(sizeof(int) * (high - mid));
    int count = 0;
    for(int i = low ; i <= mid ; i++){
        A[count] = arr[i];
        count++;
    }
    count = 0;
    for(int j = mid + 1  ; j <= high ; j++){
        B[count] = arr[j];
        count++;
    }
    int i, j;
    i = 0;
    j = 0; 
    count = low;
    for(; i < (mid - low + 1) && j < (high - mid) ; ){
        if(A[i] <= B[j]){
            arr[count] = A[i];
            i++;
            count++;
        }
        else if(A[i] > B[j]){
            arr[count] = B[j];
            j++;
            count++;
        }
    }
    while(i < mid - low + 1){
        arr[count] = A[i];
        count++;
        i++;
    }
    while(j < (high - mid)){
        arr[count] = B[j];
        count++;
        j++;
    }
    for(int i = low ; i <= high ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
    mergesort(0, n - 1);
    for(int i = 0 ; i < n ; i++){
        printf("%d\t", arr[i]);
    }
}