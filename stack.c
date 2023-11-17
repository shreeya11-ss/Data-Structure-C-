
#include <stdio.h>
#include <stdlib.h>
#define n 5

struct stack
{
    int arr[n];
    int t;
};
struct stack s;
void pop();
void push();
void top();
void display();
int main()
{
    int x;
    printf("Stack Implementation\n");
   
    while (1)
    {
        printf("Enter your choice\n 1.pop \n 2.push \n 3.top \n 4.display \n");
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

void pop()
{
    if (s.t == -1)
    {
        printf("stack is empty");
    }
    else
    {
        --s.t;
    }
}
void push()
{
    if (s.t == 4)
    {
        printf("stack is full");
    }
    else
    {
        int x;
        printf("enter element to be inserted:");
        scanf("%d", &x);
       
        s.t += 1;
        s.arr[s.t] = x;
    }
}
void top()
{
    if (s.t == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d\n",s.arr[s.t]);
    }
}
void display()
{
    if (s.t == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (int i=0; i<=s.t; i++)
        {
            printf("%d\n",s.arr[i]);
        }
    }
}