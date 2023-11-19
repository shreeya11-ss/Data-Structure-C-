#include <stdio.h>
#include <stdlib.h>
struct dll
{
    int data;
    struct dll *prev, *next;
};
struct dll *head;
void insert_begin();
void insert_random();
void insert_end();
void delete_begin();
void delete_random();
void delete_end();
void display();
void reverse();
void main()
{
    int x;
    head = NULL;
    while (1)
    {
        printf("\n1.insert at front\n2.Insert at random\n3.insert at end\n4.delete at front\n5.delete at random\n6.delete at end\n7.display\n8.reverse\n");
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
        case 8:
            reverse();
            break;

        default:
            printf("invalid");
        }
    }
}
void insert_begin()
{
    struct dll *node;
    int p;
    node = (struct dll *)malloc(sizeof(struct dll));
    printf("enter data:");
    scanf("%d", &p);
    node->data = p;
    node->prev = NULL;
    node->next = NULL;
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        node->prev = NULL;
        node->next = head;
        head->prev = node;
        head = node;
    }
}
void insert_end()
{
    struct dll *node, *temp;
    int p;
    printf("Enter data:");
    scanf("%d", &p);
    node = (struct dll *)malloc(sizeof(struct dll));
    node->data = p;
    node->next = NULL;
    node->prev = NULL;
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
        node->prev = temp;
        node->next = NULL;
    }
}
void insert_random()
{
    int pos, p, i;
    struct dll *node, *temp;
    node = (struct dll *)malloc(sizeof(struct dll));
    if (pos < 0)
    {
        printf("invalid position");
    }
    else
    {
        printf("enter position:");
        scanf("%d", &pos);
        printf("enter data:");
        scanf("%d", &p);
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        node->data = p;
        node->next = temp->next;
        node->prev = temp;
        temp->next = node;
        node->next->prev = node;
    }
}
void delete_begin()
{
    struct dll *temp;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
void delete_end()
{
    struct dll *temp, *prevnode;
    if (head == NULL)
    {
        printf("list is empty");
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
void delete_random()
{
    int pos,i=1;
    struct dll *temp,*temp2;
         printf("\nenter location of the node:");
         scanf("%d", &pos);
        temp = head;
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        temp2->next->prev=temp;
        free(temp2);
        
}

void display()
{
    struct dll *temp;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("[%p|%d|%p]-->", temp->prev, temp->data, temp->next);
            temp = temp->next;
        }
    }
}
void reverse()
{
    struct dll *temp,*temp2;
    temp=head;
    while(temp!=NULL){
        temp2=temp->prev;
        temp->prev=temp->next;
        temp->next=temp2;
        temp=temp->prev;
    }
    if(temp2!=NULL){
        head=temp2->prev;
    }
}
