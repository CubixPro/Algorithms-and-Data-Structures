#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char str[1000];
    char enc[2000];
    unsigned long long int val=0;
    gets(str);
    for(int i = 0 ; i < strlen(str) ; i++)
    {
        char ch = str[i];
        val = val*100 + (int)ch;
        //printf("%llu\n", val);
       
       
    }
    printf("%llu\n", val);
    unsigned long long int part1 = val/(unsigned long long int)(pow(10, strlen(str)));
    unsigned long long int part2 = val%(unsigned long long int)(pow(10, strlen(str)));
    unsigned long long int part3 = part1 + part2;
    printf("%llu %llu %llu\n", part1, part2, part3%4447);
}