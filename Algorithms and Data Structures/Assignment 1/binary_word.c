#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i ;
	int n;
	char str[1000];
	scanf("%d", &n);
	char** arr = (char**)malloc(n * sizeof(char*));
	for(i = 0 ;  i < n ; i++)
	{
		arr[i] = (char *)malloc(1000 * sizeof(char));
		scanf("%s", arr[i]);
	}
	/*for(i = 0 ; i < n ; i++)
	{
		printf("%s\n", arr[i]);
	}*/
	int found = 0 ;
	char find[1000];
	scanf("%s", find);
	int l = 0 ; 
	int u = n - 1 ;
	int m = (l + u)/2;
	while(l < u)
	{
		if(strcmp(find, arr[m]) < 0)
		{
			u = m - 1;
			m = l + u;
			m = m/2;
		}
		else if(strcmp(find, arr[m]) > 0)
		{
			l = m + 1;
			m = (l + u)/2;
		}
		else
		{
			found = 1;
			printf("found at %d\n", (m + 1));
			break;
		}
	}
	if(found == 0)
	{
		printf("not found \n");
	}
}
   
	
