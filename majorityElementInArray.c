#include <stdio.h>
#include <string.h>
char stack[100];
int top=-1;

void push(char c){
    stack[++top]=c;
}


char pop(){
    if(top<0){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}
void recognize(char str[]){
    int i=0,flag=0;
    char next = str[i];
    push('c');
    while(next !='c'){
        push(next);
        i++;
        next = str[i];
    }
        i++;
        next = str[i];
    while(next != '\0'){
        if(stack[top] == 'c'){
            break;
        }
        char temp= pop();
        if(temp != next){
            flag=1;
            break;
        }
        i++;
        next = str[i];
    }
    if(flag==0){printf("it is grammar string");}
    else{printf("it is not grammar string");}
}
void main(){
    char str[100];
    printf("Enter the String :");
    scanf("%s",str);
    recognize(str);
}