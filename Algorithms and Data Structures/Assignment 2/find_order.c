#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int* arr = (int *)malloc(sizeof(int) * size);
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d", &arr[i]);
    }
    int state;//1 is increasing, -1 is decreasing, 0 is constant, 2 means not sorted
    if(arr[0] == arr[1])
    {
        state = 0;
    }
    else if(arr[1] > arr[0])
    {
       state = 1; 
    }
    else
    {
        state = -1;
    }
    
    
    for(int i = 2 ; i < size  ; i++)
    {
        if(state == 0)
        {
            if(arr[i] > arr[i - 1])
            {
                state = 1;
            }
            else if(arr[i] == arr[i - 1])
            {
               state = 0; 
            }
            else
            {
                state = -1;
            }
        }
        else
        {
            if(arr[i] >= arr[i - 1] && state == 1)
                continue;
            else if(arr[i] <= arr[i - 1] && state == -1)
                continue;
            else
            {
                state = 2;
                break;
            }
            
        }
        printf("%d\n", state);

        

    }
    switch (state)
    {
    case 1:
        printf("Increasing");
        break;
    case 2:
        printf("");
    
    default:
        break;
    }
}