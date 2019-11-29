#include<stdio.h>

int main()
{
	int a, b;
	a = 1;
	b = 1;
	int c = a + b;
	int i = 3;
	while(c > 0)
	{
		a = b;
		b = c;
		c = a + b;
		i++;
	}
	printf("Maximum : %d\n", i - 1);
	
	
}
