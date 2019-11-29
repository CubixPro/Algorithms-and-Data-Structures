#include<stdio.h>
#define int long long int
int fact(int n)
{
	if(n <= 1)
		return 1;
	else 
		return n*fact(n - 1);
}
int main()
{
	int check = 1;
	while(1 == 1)
	{
		if(fact(check) < 0)
		{
			printf("Maximum is %d\n", check - 1);
			break;
		}
		check++;
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", fact(n));
	
}
