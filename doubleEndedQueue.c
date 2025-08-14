int r = 0, f = 0;
void insertAtLast(int val , int size , int queue[]){

    if (r >= size)
    {
        printf("Queue overflow");
    }
    queue[r++] = val;        
}

void insertAtFirst(int val , int size , int queue[]){
    
}


void dequeue(int size , int queue[]){
    if (r == f)
    {
        printf("queue underflow");
    }
    f++;
}
void display(int queue[] , int size){
    for (int i = f; i < r; i++)
    {
        printf("%d " , queue[i]);
    }   
}
int main(){
    int size;
    printf("Enter the size of queue: ");
    scanf("%d" , &size);
    int queue[size];
    enque(5 , size , queue);
    enque(10 , size , queue);
    enque(15, size , queue);
    enque(20 , size , queue);
    
    display(queue , size);
    
    dequeue(size , queue);
    dequeue(size , queue);
    printf("\n");
    display(queue , size);

}