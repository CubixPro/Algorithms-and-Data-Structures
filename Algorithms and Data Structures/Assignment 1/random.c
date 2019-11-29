#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    //time_t = t;
    fp = fopen("text.txt", "w");
    if(fp != NULL)
    {
        for(int i = 0 ; i < 100000 ; i++)
        {
            srand(i);
        int val = rand()%100000;
       
        fprintf(fp, "%d", val);
        fputs("\n", fp);
        }
    }
}