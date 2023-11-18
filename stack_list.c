#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
void push();
void pop();
void top();
void display();

struct stack *head;
void main(){
    int x;
    printf("Stack Implementation\n");
    while (1)
    {
        printf("\nEnter your choice\n 1.pop \n 2.push \n 3.top \n 4.display \n");
        printf("choice:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            pop();
            break;
        case 2:
            push();
            break;
        case 3:
            top();
            break;
        case 4:
            display();
            break;
        default:
            printf("invalid");
            break;
        }
    }
}

void push(){
    int p;
    struct stack *node;
    node=(struct stack*)malloc(sizeof(struct stack));
    printf("enter data:");
    scanf("%d",&p);
    node->data=p;
    node->next=NULL;
    if(head==NULL){
        head=node;
    }
    else{
        node->next=head;
        head=node;
    }
    
}
void pop(){
    struct stack *temp;
    if(head==NULL){
        printf("stack is empty");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }

}
void display(){
    struct stack *temp;
    temp=head;
    if(temp==NULL){
        printf("stack is empty");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d\n---\n",temp->data);
            temp=temp->next;
        }
    }
}
void top(){
    struct stack *temp;
    temp=head;
    if(temp==NULL){
        printf("stack is empty");
    }
    else{
        printf("%d",temp->data);
    }
}