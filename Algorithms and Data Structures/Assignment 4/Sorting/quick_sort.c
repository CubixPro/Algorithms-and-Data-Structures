#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10000

int arr[MAX_SIZE];

int partition(int, int);

void quickSort(int low, int high){
    if(low < high){
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int partition(int low, int high){
    int v = arr[low];
    int i = low + 1;
    int p = high;
    while(i < (p)){
        while(!(arr[i] >= v) && (i < (p))){
            i++;
        }
        while(!(arr[p] <= v) && (i < (p))){
            p--;
        }
        int temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
    }
    if(arr[low] > arr[p]){
        int temp = arr[p];
        arr[p] = arr[low];
        arr[low] = temp;
        return p;
    }
    else return low;
    
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(0, n - 1);
    for(int i = 0 ; i < n ; i++){
        printf("%d\t", arr[i]);
    }
}
