#include<stdio.h>
int r = 0, f = 0;
void enque(int val , int size , int queue[]){

    if ((r+1)%size == f)
    {
        printf("Queue overflow");
        return;
    }


    queue[r] = val;
    r = (r+1)%size;
}

void dequeue(int size , int queue[]){
    if (f == r)
    {
        printf("queue overflow");
        return;
    }
    f = (f+1)%size;
}
void display(int queue[] , int size){
    if (f == r)
    {
        printf("Queue is empty\n");
        return;
    }
    
    int i = f;
    while (i != r) {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("\n");  
}
int main(){
    int size;
    printf("Enter the size of queue: ");
    scanf("%d" , &size);
    int queue[size];
    enque(5, size, queue);
    enque(10, size, queue);
    enque(15, size, queue);
    display(queue, size);

    dequeue(size, queue);
    dequeue(size, queue);
    display(queue, size);

    enque(20, size, queue);
    enque(25, size, queue);
    display(queue, size);

}