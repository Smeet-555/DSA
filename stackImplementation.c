#include <stdio.h>

#define N 3
int top = -1;
int s[N];

void push(int value) {
    if (top >= N - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        s[top] = value;
        printf("%d  ", value);
    }
}
int pop(){
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int val = s[top];
        top--;
        return val;
    }
}
void disply(){
    if(top == -1){
        printf("Stack is empty:\n");
    }else{
        printf("your Stack is : ");
        for(int i=top;i>=0;i--){
            printf("%d  ",s[i]);
        }
    }
}
int peep(int i){
    if(top - i + 1 < 0){
        printf("Stack is underflow :");
    }else{
        return s[top - i + 1];
    }
}
void main()
{
    int n;
    printf("Enter 1 to call push method in stack :\n");
    printf("Enter 2 to call pop method in stack :\n");
    printf("Enter 3 to call disply method in stack :\n");
    printf("Enter 4 to call peep method in stack :\n");
    printf("Enter 5 to call change method in stack :\n");
    printf("Enter your choice :");
    scanf("%d", &n);

    if (n == 1)
    {
        push(12);
        push(13);
        push(14);
        return;
    }
     if (n == 2)
    {
        push(12);
        push(13);
        push(14);
        printf("Popped: %d\n", pop());
        return;
    }
    if(n == 3){
        push(5);
        push(10);
        push(12);
        disply();
        return;
    }if(n == 4){
        int i;
        printf("Enter a number of peep element:");
        scanf("%d",&i);
        push(5);
        push(10);
        push(15);
        peep(i);
    }

}