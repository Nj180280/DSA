#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data; 
    struct stack *next;
};
struct stack *ptr;
struct stack *top;
int push()
{
    int val;
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val); 
    struct stack *pnew=(struct stack *)malloc(sizeof(struct stack)); 
    pnew->data=val;
    if(top==NULL)
    {
        pnew->next=NULL; 
        top=pnew;
        return top;
    }
    else
    {
        pnew->next=top; 
        top=pnew;
        return top;
    }
}
int pop()
{
    ptr=top;
    if(top==NULL)
    {
        printf("STACK UNDERFLOW!!\n"); 
    }
    else
    {
        top=top->next;
        printf("value currently being deleted is:%d\n",ptr->data);
        free(ptr);
    }
    return top;
}
int display()
{
    ptr=top;
    if(top==NULL)
    {
        printf("STACK UNDERFLOW!!\n"); 
    }
    printf("STACK IS:\n"); 
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data); 
        ptr=ptr->next;
    }  
}
int peek()
{
    if(top==NULL)
    {
        printf("STACK UNDERFLOW!!\n"); 
    }
    else
    {
    printf("value currently at top:%d\n",top->data);
    }
}
void main()
{
    top=NULL;
    int cho;
    do
    {
    printf("OPTIONS ARE AS FOLLOWS:\n"); 
    printf("1)PUSH\n2)POP\n3)PEEK\n4)DISPLAY\n5)EXIT\n"); 
    printf("ENTER YOUR CHOICE:\n");
    scanf("%d",&cho);
    switch(cho)
    {
        case 1:
        top = push(top); 
        break;

        case 2:
        top = pop(top); 
        break;

        case 3:
        top = peek(top); 
        break;

        case 4:
        top = display(top); 
        break;

        default:
        printf("ENTER CHOICE BETWEEN 1-4\n");
    }
    }while(cho!=5);
}