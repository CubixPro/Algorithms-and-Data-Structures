#include<stdio.h>
#include"singly_linked_list_header.h"
#define MAX 10

int counter = 0;
typedef struct Node
{
    int data;
    struct Node* next;
} node;
node* head_ref[MAX] ;

//function prototypes
int return_size(node*);//just to show null error
void create_a_list();
void print_a_list();
void print_a_particular_list(int);
void print_all_list();
void print_in_reverse_main();
void print_in_reverse(node*);
void find_number_of_nodes();
void compare_two_lists();
void delete();



int main()
{    
   while(1)
   {
        printf("\n****************MENU**************\n");
        printf("1. create a list\n");
        printf("2. print the list\n");
        printf("3. print a list in reverse order\n");
        printf("4. Find number of nodes of a particular list\n");
        printf("5. Compare two lists\n");
        printf("6. Delete\n");
        printf("***************************************\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create_a_list();break;
            case 2: print_a_list();break;
            case 3: print_in_reverse_main();break;
            case 4: find_number_of_nodes();break;
            case 5: compare_two_lists();break;
            case 6: delete();
            default: printf("INVALID CHOICE!!!\n");break;
        }    
   }
    return 0;
}

void create_a_list()
{
    if(counter >= MAX) 
    {
        printf("CAN'T INITIALIZE A NEW LIST\nMaximum number of list limit rached!!\n");
        return;
    }
    else
    {
        printf("Enter your data: ");
        int info;
        scanf("%d",&info);
        head_ref[counter] = init_l();
        head_ref[counter]->data = info;
        printf("A new list has been created!!\n");
    }
}

void print_a_list()
{
    printf("\n1. print a particular list\n");
    printf("2.print all lists\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: printf("Enter the number of list you want to print: ");
                int choice;
                scanf("%d",&choice);
                choice--;
                print_a_particular_list(choice);
                break;
        case 2: print_all_list();break;
        default: printf("INVALID INPUT\n"); break;
    }
}

void print_a_particular_list(int choice)
{
    node* head = head_ref[choice];
    if(empty_l(head))
    {
        printf("the list is empty!!\n");
    }
    else
    {
        while(head->next != NULL)
        {
            printf("%d->",head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
    
}

void print_all_list()
{
    int i;
    for(i=0;head_ref[i] != '0';i++)
    {   
        print_a_particular_list(i);
    }
}
void print_in_reverse_main()
{
    printf("Enter the number of list you want to print: ");
    int choice;
    scanf("%d",&choice);
    choice--;

    node* head = head_ref[choice];
     if(head == NULL) 
    {
        printf("List doesn't exist or somehow deleted!!!!\n");
        return;
    }
    print_in_reverse(head);
}
void print_in_reverse(node* head)
{
    if(head == NULL) 
    {
        return;
    }
    else
    {
        print_in_reverse(head->next);
        printf("%d->",head->data);
    }
    printf("NULL\n");
}

void find_number_of_nodes()
{
    printf("Enter the number of list you want to print: ");
    int choice;
    scanf("%d",&choice);
    choice--;
    node* head = head_ref[choice];
    if(head == NULL) 
    {
        printf("List doesn't exist or somehow deleted!!!!\n");
        return;
    }
    else
    {
        int count = return_size(head);
        printf("NUmber of nodes of list%d: %d\n",choice+1,count);
    }
}
int return_size(node* head)
{   
    int count = 0;
    while(head->next != NULL)
    {
        count++;
    }
    count++;
    return count;
}

void compare_two_lists()
{
    printf("Enter the number of first list: ");
    int choice1;
    scanf("%d",&choice1);
    choice1--;
    node* head1 = head_ref[choice1];
    printf("Enter the number of second list: ");
    int choice2;
    scanf("%d",&choice2);
    choice2--;
    node* head2 = head_ref[choice2];
    if(head1 == NULL || head2 == NULL) 
    {
        printf("List doesn't exist or somehow deleted!!!!\n");
        return;
    }
    else
    {
        if(!empty_l(head1) && !empty_l(head2))//lists are not empty
        {
            int size1 = return_size(head1);
            int size2 = return_size(head2);
            if(size1 != size2)
            {
                printf("Lists are unequal!!\n");
                return;
            }
            else
            {   
                int flag = 0;
                while(head1->next != NULL && head2->next != NULL)
                {
                    if(head1->data != head2->data)
                    {
                        printf("LIsts are unequal\n");
                        flag = 1;
                        return;
                    }
                    if(flag == 0 && head1->data == head2->data)
                    {
                        printf("Lists are EQUAL!!\n");
                        return;
                    }

                }
            }
            
        }
        else if(empty_l(head1) && empty_l(head2))
        {
            printf("Lists are EQUAL!!\n");
            return;
        }
        else 
        {
            printf("Lists are UNEAUAL!!!\n");
            return;
        }    
    }
}
void delete()
{
    printf("1. delete a complete list\n");
    printf("2. delete a particular element of a list\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: 
            printf("Enter the list number: ");
            int mama;
            scanf("%d",&mama);
            mama--;
            node* curr = head_ref[mama];
            delete_a_list(node* curr);
            break;
        case 2:
             printf("Enter the list number: ");
            int mama;
            scanf("%d",&mama);
            mama--;
            node* curr = head_ref[mama];
            delete_a_particular_number(curr);
            break;
    }
}

void delete_a_list(node* head)
{
    
}
