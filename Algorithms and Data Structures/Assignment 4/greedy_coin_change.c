#include <stdio.h>

void greedy(int amount)
{
	int denominations[] = {50, 25, 10, 5, 1};
	int number[5] = {0};
	int size = 5;
	int i = 0;
	while (i < size)
	{
		while(amount >= denominations[i])
		{
			amount = amount - denominations[i];
			number[i]++;
		}
		i++;
	}
	for (i = 0; i < size; i ++)
		printf("Rs. %d - %d \n", denominations[i], number[i]);
}

int main()
{
	printf("Enter total money : ");
	int num;
	scanf("%d", &num);
	greedy(76);
	return 0;
}