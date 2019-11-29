#include<stdio.h>
#define int long long int
int dp[1000000];
int fibbo(int n)
{
	if(dp[n] != -1)
		return dp[n];
	else
	{
		dp[n] = fibbo(n - 1) + fibbo(n - 2);
		return dp[n];
	}
}
int main()
{
	
	int i ;
	for(i = 0 ; i <= 99999 ; i++)
	{
		dp[i] = -1;
	}
	dp[1] = 1;
	dp[2] = 1;
	int check = 1;
	while(check != 1000000)
	{
		int val = fibbo(check);
		if(val < 0)
		{
			printf("The maximum is %d\n", check - 1);
			break;
		}
		check++;
	}
	int n ;
	scanf("%d", &n);
	printf("%d\n", fibbo(n));
}
