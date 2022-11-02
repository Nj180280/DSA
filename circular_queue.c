#include<stdio.h>
#define size 4
struct queue
{
    int f; 
    int r;
    int a[size];
}q;
void enqueue(int val)
{
    if((q.r+1)%size==q.f)
    {
        printf("QUEUE OVERFLOW\n"); 
    }
    if(q.f==-1) //1st element to be inserted
    {
        q.f=q.r=0; 
        q.a[q.r]=val;
    }
    else
    {
        (q.r++)%size; 
        q.a[q.r]=val;
    }
}
int dequeue()
{
    int temp;
    if(q.f==-1)
    {
        printf("QUEUE UNDERFLOW"); 
    }
    temp=q.f;
    if(q.f==q.r)
    {
        q.f=q.r=-1; 
    }
    else
    {
        (q.f++)%size;
    }
    return temp;
}
void peek()
{
    if(q.f==-1)
    {
        printf("QUEUE UNDERFLOW"); 
    }
    else
    {
        printf("value at front is:%d",q.a[q.f]);
    }
}
void display()
{
    if(q.f==-1)
    {
        printf("QUEUE UNDERFLOW"); 
    }
    else
    {
        printf("QUEUE IS:");
        for(int i=q.f;i!=q.r+1;i++)
        {
            printf("%d\n",q.a[i]);
        }
    }
}
void main()
{
    int cho,val;
    q.f=q.r=-1;
    do
    {
    printf("OPTIONS ARE AS FOLLOWS:\n"); 
    printf("1)ENQUEUE\n2)DEQUEUE\n3)PEEK\n4)DISPLAY\n5)EXIT\n");
    printf("ENTER YOUR CHOICE:\n"); 
    scanf("%d",&cho);
    switch(cho)
    {
        case 1:
        printf("enter value to be inserted:\n"); 
        scanf("%d",&val);
        enqueue(val); 
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