#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max_string 1000
void selection(int A[], int n, int ch)
{
  int i;
  if (ch == 1)
    for (i = 0; i < (n - 1); i++)
    {
      int min_index = i;
      for (int j = i + 1; j < n; j++)
      {
        if (A[j] < A[min_index])
          min_index = j;
      }
      int temp = A[min_index];
      A[min_index] = A[i];
      A[i] = temp;
    }
  else if (ch == -1)
    for (i = 0; i < (n - 1); i++)
    {
      int max_index = i;
      for (int j = i + 1; j < n; j++)
      {
        if (A[j] > A[max_index])
          max_index = j;
      }
      int temp = A[max_index];
      A[max_index] = A[i];
      A[i] = temp;
    }
}

void selection_string(char A[][Max_string], int n)
{
  int i;
  for (i = 0; i < (n - 1); i++)
  {
    int min_index = i;
    for (int j = i + 1; j < n; j++)
    {
      if (strcmp(A[j], A[min_index]) < 0)
        min_index = j;
    }
    char temp[Max_string];
    strcpy(temp, A[min_index]);
    strcpy(A[min_index], A[i]);
    strcpy(A[i], temp);
  }
}
int main(){
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
    selection(0, n - 1, 1);
    for(int i = 0 ; i < n ; i++){
        printf("%d\t", arr[i]);
    }
}