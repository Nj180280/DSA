#include<stdio.h>
#define size 6
struct queue
{
    int f,r; 
    int a[size]; 
}q1;
void enqueue()
{
    int a;
    if(q1.r==size-1)
    {
        printf("QUEUE OVERFLOW!!\n"); 
    }
    else if(q1.f==-1&&q1.r==-1)
    {
        q1.f=q1.r=0; 
    }
    else
    {
        printf("enter value to be pushed:\n"); 
        scanf("%d",&a); 
        q1.r++;
        q1.a[q1.r]=a; 
    }
}
int dequeue()
{
    int temp; 
    if(q1.f==-1||(q1.f>q1.r))
    {
        printf("QUEUE UNDERFLOW!!\n"); 
    }
    else
    {
        temp=q1.f;
        q1.f++; 
        if(q1.f>q1.r)
        q1.f=q1.r=-1;
        return temp;
    }
}
void peek()
{
    if(q1.f==-1||(q1.f>q1.r))
    {
        printf("QUEUE UNDERFLOW!!\n"); 
    }
    else
    {
        printf("frontmost element is:\n"); 
        printf("%d\t",q1.a[q1.f]);
    }
}
void display()
{
    if(q1.f==-1||(q1.f>q1.r))
    {
        printf("QUEUE UNDERFLOW!!\n"); 
    }
    else
    {
        printf("QUEUE IS\n");
        for(int i=q1.f;i<=q1.r;i++)
        {
            printf("%d\t",q1.a[i]);
        }
    }
}
void main()
{
    int cho;
    q1.f=-1; 
    q1.r=-1; 
    do
    {
    printf("options are as follows : \n1)enqueue\n2)dequeue\n3)peek\n4)display\n5)EXIT\n"); 
    printf("enter your choice:\n"); 
    scanf("%d",&cho);
    switch(cho)
    {
        case 1: 
        enqueue(); 
        break; 

        case 2:
        dequeue(); 
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