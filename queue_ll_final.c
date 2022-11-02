#include<stdio.h>
#include<stdlib.h>
struct queue
{
    struct queue *next; 
    int data; 
};
struct queue *front=NULL; 
struct queue *rear=NULL;
int enqueue(struct queue *front,int val,struct queue *rear)
{
    struct queue *pnew=(struct queue *)malloc(sizeof(struct queue)); 
    pnew->data=val;
    pnew->next=NULL;
    if(pnew==NULL)
    {
        printf("QUEUE OVERFLOW!!\n");
    } 
    if(front==NULL) //EMPTY QUEUE
    {
        front=rear=pnew;
    }
    else
    {
    rear->next=pnew;
    rear=pnew; 
    }
}
int dequeue(struct queue *front)
{
    struct queue *temp=front; 
    if(front==NULL && rear==NULL) //EMPTY QUEUE
    {
        printf("QUEUE UNDERFLOW!!\n"); 
    }
    if(front==rear)
    {
        front=rear=NULL; 
    }
    else
    {
        front=front->next; 
    }
    free(temp); 
}
int display(struct queue *front)
{
    struct queue *temp=front; 
    if(front==NULL && rear==NULL) //EMPTY QUEUE
    {
        printf("QUEUE UNDERFLOW!!\n"); 
    }
    printf("QUEUE IS:\n"); 
    while(temp!=NULL)
    {
        printf("%d\n",temp->data); 
        temp=temp->next; 
    }
}
void main()
{
    int cho,val;
    do
    {
        printf("\nCHOICES ARE AS FOLLOWS:\n"); 
        printf("\n1)ENQUEUE\n2)DEQUEUE\n3)DISPAY\n4)EXIT\n"); 
        printf("\nENTER YOUR CHOICE:\n"); 
        scanf("%d",&cho); 
        switch(cho)
        {
            case 1:
            printf("enter value to be inserted:\n"); 
            
            scanf("%d",&val);
            enqueue(front,val,rear); 
            break; 

            case 2:
            dequeue(front); 
            break; 

            case 3:
            display(front); 
            break; 

            default :
            printf("ENTER CHOICES BETWEEN 1-4\n"); 
        }
    }while(cho!=4); 
}