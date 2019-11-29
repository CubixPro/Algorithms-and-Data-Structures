#include<stdio.h>
#define null -1


int list[1000];
int head = 0;

void display_list()
{
    for(int i = head; i < 1000 ; i++)
    {
        if(list[i] == null)
            return ;
        else
        {
            printf("%d ", list[i]);
        }
        
    }
}

void add_element_end(int ele)
{
    int i;
    for(i = head ; i < 1000 ; i++)
    {
        if(list[i] == null)
            break;
    }
    list[i] = ele;
    list[++i] = null;
}

void add_element_after(int ele, int node)
{
    int temp;
    for(int i = head; i < 1000 ; i++ )
    {
        if(temp == -1)
        {
            list[i] = temp;
            break;
        }
        if(i == (node + 1))
        {
            temp = list[i];
            list[i] = ele;
        }
        else if(i >= (node + 1))
        {
            int t = list[i];
            list[i] = temp;
            temp = t;
        }
    }
}

int del_element(int node)
{
    int del;
    for(int i = head ; i < 1000 ; i++)
    {
        if(list[i] == -1)
            break;
        if(i == node)
        {
            del = list[i];
            list[i] = list[i + 1];
        }
        if(i > node)
        {
            list[i] = list[i + 1];
        }
    }
    return del;
}

class Transaction{

};

int main()
{
    list[0] = -1;
    add_element_end(1);
    add_element_end(2);
    add_element_end(3);
    del_element(2);
    display_list();
}