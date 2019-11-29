#include<stdio.h>
#include<stdlib.h>


#define MAX_SIZE 1000
#define null '\0'

void display_str(const char* str)
{
    for(int i = 0 ; i < MAX_SIZE ; i++)
    {
        if(str[i] != null)
            printf("%c", str[i]);
        else
        {
            break;
        }
        
    }
}

int str_length(const char* str)
{
    int count = 0 ;
    for(int i = 0 ; i < MAX_SIZE ; i++)
    {
        if(str[i] != null)
            count++;
        else
        {
            return count;
        }
        
    }
}

char* new_str()
{
    char* str;
    str = (char *)malloc(sizeof(char) * MAX_SIZE);
    return str;
}

char* concatenate_str(const char* s1, const char* s2)
{
   char* s3 = new_str(); 
   for(int i = 0 ; i < str_length(s1); i++)
   {
       s3[i] = s1[i];
   }
   for(int i = 0 ; i < str_length(s2) ; i++)
   {
       s3[i + str_length(s1)] = s2[i];
   }
   return s3;
}

int equals(const char* s1, const char* s2)//0 is false, 1 is true
{
    if(str_length(s1) == str_length(s2))
    {
        for(int i = 0 ; i < str_length(s1) ; i++)
        {
            if(s1[i] != s2[i])
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int compareTo(const char* s1, const char* s2)
{
    for(int i = 0 ; i < MAX_SIZE ; i++)
    {

        if(s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        if(s1[i] == null)
        {
            break;
        }
    }
    return 0;
}

int indexOf(const char* str, char ch)
{
    for(int i = 0 ; i < MAX_SIZE ; i++)
    {
        if(str[i] == null)
            return -1;
        if(str[i] == ch)
            return i;
    }
}
int main()
{
    char *ch = new_str();
    ch = "hello";
    char *ch2 = new_str();
    ch2 = "pink";
    char* ch3 = concatenate_str(ch, ch2);
    display_str(ch3);
    char *ch4 = new_str();
    ch4 = "hellopink";
    printf("%d", indexOf(ch, 't'));

}