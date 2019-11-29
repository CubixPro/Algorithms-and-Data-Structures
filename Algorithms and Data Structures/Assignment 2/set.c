#include<stdio.h>

typedef struct{
    int set[1000];
    int size ;
}SET;

void init_set(SET* s)
{
    s->size = 0 ;
}
void add_element(SET *s, int ele)
{
    if(s->size == 1000)
    {
        printf("Overflow");
    }
    for(int i = 0 ;  i < s->size  ; i ++)
    {
        if(s->set[i] == ele)
            return;
        
    }
    s->set[s->size] = ele;
    s->size++;
}

SET union_sets(const SET s1,const SET s2)
{
    SET s3;
    init_set(&s3);
    for(int i = 0 ; i < s1.size ; i++)
    {
        add_element(&s3, s1.set[i]);
    }
    for(int j = 0 ; j < s2.size ; j++)
    {
        add_element(&s3, s2.set[j]);
    }
    return s3;
}

int element_exists(const SET s, int ele)
{
    for(int i = 0 ; i < s.size ; i++)
    {
        if(ele == s.set[i])
        {
            return 1;//true;
        }
    }
    return 0;//false
}

SET intersection_sets(const SET s1,const SET s2)
{
    SET s3;
    init_set(&s3);
    for(int i = 0 ; i < s1.size ; i++)
    {
        if(element_exists(s2, s1.set[i]) == 1)
        {
            add_element(&s3, s1.set[i]);
        }
    }
    for(int i = 0 ; i < s2.size ; i++)
    {
        if(element_exists(s1, s2.set[i]) == 1)
        {
            add_element(&s3, s2.set[i]);
        }
    }
    return s3;
}

void display(const SET s)
{
    for(int i = 0 ; i < s.size ; i++)
        printf("%d ", s.set[i]);
    printf("\n");
}

SET difference_sets(SET s1, SET s2)
{
    SET s3;
    init_set(&s3);
    for(int i = 0 ; i < s1.size ; i++)
    {
        if(element_exists(s2, s1.set[i]) == 0)
        {
            add_element(&s3, s1.set[i]);
        }
    }
    return s3;
}

int main()
{
    SET s;
    init_set(&s);
    add_element(&s, 1);
    add_element(&s, 2);
    add_element(&s, 3);
    display(s);
    SET s2;
    init_set(&s2);
    add_element(&s2, 2);
    add_element(&s2, 3);
    add_element(&s2, 4);
    display(s2);
    SET s3 = union_sets(s, s2);
    display(s3);
    SET s4 = intersection_sets(s, s2);
    display(s4);
    SET s5 = difference_sets(s, s2);
    display(s5);


}

