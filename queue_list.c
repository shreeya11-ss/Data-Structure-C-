#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *front , *rear ;

void enqueue();
void dequeue();
void display();
void main()
{
    int x;
    while (1)
    {
        printf("Queue Operations:\n");
        printf("1.Insert\n2.Delete\n3.Display\n");
        printf("Enter your choice:");
        scanf("%d", &x);

        switch (x)
        {
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
void enqueue()
{
    int p;
    struct queue *node;
    node = (struct queue *)malloc(sizeof(struct queue));
    printf("enter data:");
    scanf("%d", &p);
    node->data = p;
    node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = node;
    }
    else
    {
        rear->next=node;
        rear = node;
    }
}
void dequeue()
{
    struct queue *temp;
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct queue *temp;
    if (front == 0 && rear == 0)
    {
        printf("queue is empty");
    }
    else
    {
        temp =front;
        while (temp!=NULL)
        {
            printf("%d\n--\n", temp->data);
            temp = temp->next;
        }
    }
}