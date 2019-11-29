#include<stdio.h>
#include"stack.h"
#include<string.h>

int isp(char ch){
    switch(ch){
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case ')' : return 0;
        case '#' : return -4;
        default: return -5;
    }
}

int icp(char ch){
    switch(ch){
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case ')' : return 4;


    }
}



void insert(char* str, int len, node** s){
    
   for(int i = 0 ; i < len ; i++){
       push(str[i], s);
   } 
}

int is_operand(char ch){
    switch(ch){
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':return false;
        default : return true;
    }
}
void create_post_fix(char* str, int len, node** s){
    push('#', s);
    for(int i = 0 ; i < len ; i++){
        char x = str[i];
        if(is_operand(x)){
            printf("%c", x);
            continue;
        }
        else if(x == ')'){
            char y;
            while((y = pop(s)) != '(')
                printf("%c", y);
        }
        else if(x == '('){
            push(x, s);
            continue;
        }
        else {
            char y;
            while(isp(y = pop(s)) >= icp(x)){
                printf("%c", y);
            }
            push(y, s);
            push(x, s);
        }
    } 
    char y;
    while(!s_empty(*s)){
        char y = pop(s);
        if(y != '#')
             printf("%c", y);
    }
}


int main(){
    char str[10000];
    int length;
    scanf("%s", str);
    length = strlen(str);
    node* s;
    s_create(&s);
    create_post_fix(str, length, &s);
}