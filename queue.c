#include<stdio.h>
#define n 5
struct queue{
    int arr[n];
    int front;
    int rear;
};
struct queue q={.front=0,.rear=-1};
void enqueue();
void dequeue();
void display();
int main(){
    int x;
    while(1){
    printf("Queue Operations:\n");
    printf("1.Insert\n2.Delete\n3.Display\n");
    printf("Enter your choice:");
    scanf("%d",&x);

        switch(x){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            
            default:
            printf("invalid input\n");
            break;
        }
    }
}
void enqueue(){
    int k;
    if(q.rear==4){
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter item to be inserted:");
        scanf("%d",&k);
        q.rear++;
        q.arr[q.rear]=k;
    }
}
void dequeue(){
    if(q.front==-1||q.front>q.rear){
        printf("queue is empty\n");

    }
    else{
        q.front++;
    }
}
void display(){
     if(q.rear==-1){
        printf("queue is empty\n");

    }
    else{
        for(int i=q.front;i<=q.rear;i++){
            printf("%d\n",q.arr[i]);

        }
    }
}
