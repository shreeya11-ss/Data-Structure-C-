#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
};
struct list *head;
void insert_begin();
void insert_random();
void insert_end();
void delete_begin();
void delete_random();
void delete_end();
void display();
void search();
void main()
{
    int x;
    head = NULL;
    while (1)
    {
        printf("1.insert at front\n2.Insert at random\n3.insert at end\n4.delete at front\n5.delete at random\n6.delete at end\n7.display\n");
        printf("choice:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            insert_begin();
            break;
        case 2:
            insert_random();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_random();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            display();
            break;
        
        default:
            printf("invalid");
        }
    }
}

void insert_begin()
{
    struct list *node;
    int p;
    node = (struct list *)malloc(sizeof(struct list));
    printf("enter data:");
    scanf("%d", &p);
    node->data = p;
    node->next = NULL;
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}
void insert_end()
{
    struct list *node, *temp;
    int p;
    printf("enter data:");
    scanf("%d",&p);
    node = (struct list *)malloc(sizeof(struct list));
    node->data = p;
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void insert_random()
{
    int pos, p,i;
   
    printf("enter the position:");
    scanf("%d", &pos);
    printf("enter data:");
    scanf("%d", &p);
    
    struct list *node, *temp;
    node = (struct list *)malloc(sizeof(struct list));
    node->data = p;
    node->next = NULL;
    if (pos < 0)
    {
        printf("invalid position");
    }
    else
    {
        temp = head;
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
        
        node->next=temp->next;
        temp->next=node;
    }
}
void delete_begin()
{
    struct list *temp;
    if (head == NULL)
    {
        printf("nothing is in the list\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void delete_end()
{
    struct list *temp, *prevnode;
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            prevnode = temp;
            temp = temp->next;
        }

            if (temp == head)
            {
                head = NULL;
                free(temp);
            }
            else
            {
                prevnode->next = NULL;
                free(temp);
            }
        
    }
}
void delete_random(){
    struct list *temp, *nextnode;
    int pos,i=1;
    printf("\nEnter the location of the node:");
    scanf("%d",&pos);
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
void display(){
    struct list *temp,i;
    temp=head;
    if(temp==NULL){
        printf("lis is empty\n");

    }
    else{
        printf("elements in the list are:\n");
        while(temp!=NULL){
            printf(" [%d | %p] ",temp->data,temp->next);
            temp=temp->next;
        }

    }
    

}
