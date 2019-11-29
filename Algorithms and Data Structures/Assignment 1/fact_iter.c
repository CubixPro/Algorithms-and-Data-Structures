#include<stdio.h>
#define int unsigned long long int
int main()
{
	int n = 1;
	//scanf("%d", &n);
	
	while(1 == 1)
	{
	int prod = 1;
	int i = 1;
		for(; i <= n ; i++)
		{
		 prod = prod*i;
		 if(prod<0)
		 {
		 	printf("%llu\n", n);
		 	return;
		 }
			
		}
		n++;
	}
	//printf("%d\n", prod);

}
	
