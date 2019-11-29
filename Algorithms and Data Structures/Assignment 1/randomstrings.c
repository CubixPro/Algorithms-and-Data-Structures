#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    fp = fopen("text2.txt", "w");
    if(fp!=NULL)
    {
    for(int i = 0 ; i < 100000 ; i++)
    {
        srand(i);
        char str[10];
        for(int j = 0 ; j < 10 ; j++)
        {
            int val = (rand()%26 + 65);
            str[j]= (char)val;
        }
        fprintf(fp, "%s\n", str);
    }
    }
}