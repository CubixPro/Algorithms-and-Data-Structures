#include<stdio.h>
#include"stack.h"
#define lb printf("\n")

void print_stack_TB_c(node** s){
    while(!s_empty(*s)){
        printf("%d ", pop(s));
    }
    printf("\n");
}

void print_stack_TB_n(node** s){
    node* aux1;
    node* aux2;
    s_create(&aux1);
    s_create(&aux2);
    while(!s_empty(*s)){
        int y;
        printf("%d ", y = pop(s));
        push(y, &aux1);
    }
    while(!s_empty(aux1)){
        int y = pop(&aux1);
        push(y, s);
    }
    
    lb; 
}

void print_stack_BT_nc(node** s){
    node* aux1;
    node* aux2;
    s_create(&aux1);
    s_create(&aux2);
    while(!s_empty(*s)){
        int y = pop(s);
        push(y, &aux1);
    }
    while(!s_empty(aux1)){
        int y = pop(&aux1);
        printf("%d ", y);
        push(y, s);
    }
    
    lb; 
}

int equal(node** s1, node** s2){
    node* aux;
    s_create(&aux);
    while(!s_empty(*s1)){
        int y1, y2;
        y1 = pop(s1);
        y2 = pop(s2);
        if (y1 == y2)
        {
            push(y1, &aux);
            continue;
        }
        else{
            while(!s_empty(aux)){
                push(pop(&aux), s1);
                push(pop(&aux), s2);
            }
            return false;
        }

    }
    return true;
}


int main(){
    node* s;
    s_create(&s);
    printf("%p \n", s);
    push(4, &s);
    push(5, &s);
    push(8, &s);
    print_stack_TB_n(&s);
    print_stack_BT_nc(&s);
    node* s2;
    s_create(&s2);
    push(4, &s2);
    push(5, &s2);
    //push(8, &s2);
    printf("%d \n", equal(&s, &s2));
}