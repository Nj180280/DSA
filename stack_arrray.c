#include<stdio.h>
#define size 4
struct stack
{
    int top; 
    int a[size]; 
}s1; 
void push(int val)
{
    if(s1.top==size-1)
    {
        printf("STACK OVERFLOW!!"); 
    }
    else
    {
        s1.top++; 
        s1.a[s1.top]=val; 
    }
}
int pop()
{
    int temp; 
    if(s1.top==-1)
    {
        printf("STACK UNDERFLOW!!"); 
    }
    else
    {
        temp=s1.top; 
        s1.top--; 
        return temp; 
    }
}
void peek()
{
    if(s1.top==-1)
    {
        printf("STACK UNDERFLOW!!\n"); 
    }
    else
    {
    printf("element present at top of stack :\n"); 
    printf("%d",s1.a[s1.top]); 
    }
}
void display()
{
    printf("stack is:\n"); 
    for(int i=s1.top;i>=0;i--)
    {
        printf("%d\n",s1.a[i]); 
    }
}
void main()
{
    int cho,a; 
    s1.top=-1; 
    do
    {
    printf("options are as follows : \n1)push\n2)pop\n3)peek\n4)display\n5)EXIT\n"); 
    printf("enter your choice:\n"); 
    scanf("%d",&cho);
    switch(cho)
    {
        case 1: 
        printf("enter value to be pushed:\n"); 
        scanf("%d",&a); 
        push(a); 
        break; 

        case 2:
        pop(); 
        break; 

        case 3:
        peek(); 
        break; 

        case 4:
        display(); 
        break; 
    } 
    }while(cho!=5); 
}
