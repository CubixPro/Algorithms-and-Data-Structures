#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1
#define bool int


int main()
{
    int size;
    scanf("%d", &size);
    int *arr = (int*)malloc(sizeof(int) * size); 
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 1 ; i < size ; i++)
    {
        int val = arr[i];
        bool check = false;
        int j;
        for( j = i - 1 ; ((j >= 0) && (arr[j] > val)) ; j--)
        {
                if(arr[j] > val)
                {
                    arr[j + 1] = arr[j];
                }
                else{
                    break;
                }
                
        }
        arr[j + 1] = val;
    }
    for(int i = 0 ; i < size ;i++)
    {
        printf("%d", arr[i]);
    }
}