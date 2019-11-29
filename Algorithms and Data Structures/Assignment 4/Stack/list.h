#include<stdio.h>
#include<stdlib.h>
#define null NULL
#define true 1
#define false 0
typedef struct node node;
 struct node{
    int element;
    struct node* next;
};
void init_l(node** curr)
{
   *curr = (node *)malloc(sizeof(node));
}

int empty_l(node *head)//1 is true 0 is false
{
    if(head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int at_end(node *curr)
{
    if(curr->next == null)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert_front(node* target, node **head)
{
    target->next = *head;
    *head = target;
}
int insert_after(node* target, node *prev)
{
    if(prev != null){
        node* newhead = (node *)malloc(sizeof(node));
        newhead = prev->next;
        prev->next = target;
        target->next = newhead;
        return 0;
    }
    else
    {
            return -1;
    }
    
}
void delete_front(node **head)
{
    if(*head != null){
    node* cur = (node *)malloc(sizeof(node));
    cur = *head;
    *head = (*head)->next;
    cur = null;//why isn't free(curr) working
    }
}
void delete_after(node* prev)
{
    if(prev != null && prev->next != null)
    {
        node* curr = prev->next;
        node* act_curr = curr->next;
        prev->next = act_curr;
    }

}
void display(node* head)
{
    if(!empty_l(head)){
    while(head->next != null)
    {
        printf("%d ", head->element);
        head = head->next;
    }

    printf("%d\n", head->element);
    }
    else
    {
        printf("Empty List\n");
    }
    
}

