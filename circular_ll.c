#include<stdio.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *next;
};
struct list *head;
void display();
void insert_begin();
void insert_end();
void insert_between();
void delete_last();
void delete_any();

void main(){
    int x;
    head=NULL;
    while(1){
        printf("\nCircular Linked List operations:\n");
        printf("\n1.insert at front\n2.insert at last\n3.insert in between\n4.delete at end\n5.delete any node\n6.display\n");
        printf("choice:");
        scanf("%d",&x);
        switch(x){
            case 1:
            insert_begin();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            insert_between();
            break;
            case 4:
            delete_last();
            break;
            case 5:
            delete_any();
            break;
            case 6:
            display();
            printf("\ninvalid input");
            break;
        }
    }
}
void insert_begin(){
    struct list *node,*temp;
    int p;
    node=(struct list*)malloc(sizeof(struct list));
    printf("enter data:");
    scanf("%d",&p);
    node->data=p;
    if(head==NULL){
        head=node;
        node->next=head;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
            node->next=head;
            temp->next=node;
            head=node;
    }
}
void insert_end(){
    struct list *node,*temp;
    int p;
    node=(struct list*)malloc(sizeof(struct list));
    printf("enter data:");
    scanf("%d",&p);
    node->data=p;
    if(head==NULL){
        printf("list is empty");
        head=node;
        node->next=head;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=node;
        node->next=head;
    }
}
void insert_between(){
    int pos,p,i;
    struct list *node,*temp;
    printf("enter position:");
    scanf("%d",&pos);
    printf("enter data:");
    scanf("%d",&p);
   
    node = (struct list *)malloc(sizeof(struct list));
    node->data = p;
    if(pos<0){
        printf("invalid position");
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        node->next=temp->next;
        temp->next=node;
    }
}
void delete_last(){
    struct list *temp,*temp2;
    if(head==NULL){
        printf("list is empty");
    }
    else if(temp->next==head){
        head==NULL;
        free(head);
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=temp->next;
        free(temp);
    }
}
void delete_any(){
    struct list *temp,*nextnode;
    int pos,i;
    printf("enter position of the node:");
    scanf("%d",&pos);
    temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
void display(){
    struct list *temp;
    temp=head;
    if(head==NULL){
        printf("list is empty");
    }
    else{
        printf("elements are :");
        while(temp->next!=head){
            printf("[%d|%p]-->",temp->data,temp->next);
            temp=temp->next;
        }
        printf("[%d|%p]",temp->data,temp->next);
    }
}