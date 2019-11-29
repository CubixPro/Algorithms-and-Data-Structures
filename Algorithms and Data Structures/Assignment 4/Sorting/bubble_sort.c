#include<string.h>
#include<stdio.h>
#define MAX_STRING 1000
#include<stdlib.h>
void bubble_sort(int A[], int n, int ch) 
{
  int i, j;
  if (ch == 1) // Ascending
  {
    for(i = 0; i < (n - 1); i++)
      for(j = 0; j < (n - i - 1); j++)
        if (A[j] > A[j + 1])
  			{
  				int temp = A[j];
  				A[j] = A[j + 1];
  				A[j + 1] = temp;
  			}
  }
  else if (ch == -1) // Descending
  {
    for(i = 0; i < (n - 1); i++)
      for(j = 0; j < (n - i - 1); j++)
        if (A[j] < A[j + 1])
        {
          int temp = A[j];
          A[j] = A[j + 1];
          A[j + 1] = temp;
        }
  }
}

void bubble_string(char A[][MAX_STRING], int n)
{
  int i, j;
  for(i = 0; i < (n - 1); i++)
  {
    for(j = 0; j < (n - i - 1); j++)
    {
      if (strcmp(A[j], A[j + 1]) > 0)
      {
        char temp[MAX_STRING];
        strcpy(temp, A[j]);
        strcpy(A[j], A[j + 1]);
        strcpy(A[j + 1], temp);
      }
    }
  }
}

int main(){
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
    bubble_sort(0, n - 1, 1);
    for(int i = 0 ; i < n ; i++){
        printf("%d\t", arr[i]);
    }
}