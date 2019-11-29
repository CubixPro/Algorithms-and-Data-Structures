#include<stdio.h>
#include"list.h"

void s_create(node **s){
    
   //init_l(s); 
   *s = null;

}

int s_empty(node* s){
    return empty_l(s);
}


void s_dispose(node **s){
   while(!s_empty(*s)){
       node* ptr = *s;
       *s = (*s)->next;
       free(ptr); 
   }
}

void push(int e, node** s){
    if(!empty_l(*s)){
        node* ptr;
        init_l(&ptr);
        ptr->element = e;
        ptr->next = null;
        insert_front(ptr, s);
    }
    else{
        node* ptr;
        init_l(&ptr);
        ptr->element = e;
        ptr->next = null;
        *s = ptr;
    }
}

int pop(node** s){
   if(!empty_l(*s)){
       int val = (*s)->element;
       delete_front(s);
       return val;
   }
   else
   {
       return -999999;
   }
   
}



