#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int i;
	printf("Input the number of integers : ");
	scanf("%d", &n);
	int* arr = (int *)malloc(n * sizeof(int));
	for( i = 0 ; i < n ; i++)
	{
		scanf("%d", &arr[i]);
	}
	int find;
	int found = 0;
	scanf("%d", &find);
	for( i = 0 ; i < n ; i++)
	{
		if(arr[i] == find)
		{
			found = 1;
			printf("FOUND AT INDEX %d!\n", i + 1);
			break;
		}
	}
	if(found == 0)
		printf("NOT FOUND :(\n");
}
