#include<stdio.h>
#include<stdlib.h>
struct doubly_ll
{
    struct doubly_ll *next; 
    struct doubly_ll *prev; 
    int data;
}; 
struct doubly_ll *start=NULL;
int insert_begin(struct doubly_ll *start)
{
    int val;
    struct doubly_ll *ptr; 
    ptr=start; 
    struct doubly_ll *pnew=((struct doubly_ll *)malloc(sizeof(struct doubly_ll))); 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    pnew->data=val;
    pnew->prev=NULL; 
    pnew->next=start; 
    start=pnew; 
    return start; 
}
int insert_end(struct doubly_ll *start)
{
    int val; 
    struct doubly_ll *ptr; 
    ptr=start; 
    struct doubly_ll *pnew=((struct doubly_ll *)malloc(sizeof(struct doubly_ll))); 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    pnew->data=val; 
    ptr->next=pnew;
    pnew->prev=ptr; 
    pnew->next=NULL;
    return start; 
}
int insert_after(struct doubly_ll *start)
{
    int val,num; 
    struct doubly_ll *ptr; 
    ptr=start; 
    struct doubly_ll *pnew=((struct doubly_ll *)malloc(sizeof(struct doubly_ll))); 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    printf("enter value to be inserted after which node:\n"); 
    scanf("%d",&num);
    pnew->data=val;
    while(ptr->data!=num)
    {
        ptr=ptr->next; 
    }
    pnew->prev=ptr;
    pnew->next=ptr->next; 
    ptr->next->prev=pnew; 
    ptr->next=pnew;
    return start; 
}
int delete_begin(struct doubly_ll *start)
{
    struct doubly_ll *ptr; 
    ptr=start; 
    start=start->next; 
    start->prev=NULL; 
    free(ptr); 
    return start;
}
int delete_end(struct doubly_ll *start)
{
    struct doubly_ll *ptr; 
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next; 
    }
    ptr->prev->next=NULL;
    free(ptr); 
    return start;
}
int delete_middle(struct doubly_ll *start)
{
    int val,num;
    struct doubly_ll *ptr;
    struct doubly_ll *temp; 
    ptr=start; 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    printf("enter value to be deleted after which node:\n"); 
    scanf("%d",&num);
    while(ptr->next!=num)
    {
        ptr=ptr->next; 
    }
    temp=ptr->next; 
    ptr->next=temp->next; 
    temp->next->prev=ptr; 
    return temp;
}
void display(struct doubly_ll *start)
{
    struct doubly_ll *ptr; 
    ptr=start; 
    printf("DOUBLY LINKED LIST IS:\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data); 
        ptr=ptr->next;
    }
}
void count(struct doubly_ll *start)
{
    struct doubly_ll *ptr; 
    ptr=start; 
    int c=0;
    while(ptr!=NULL)
    { 
        ptr=ptr->next;
        c++;
    }
    printf("number of nodes are:%d\n",c); 
}
void main()
{
 int cho; 
    do
    {
    printf("CHOICES ARE AS FOLLOWS:\n"); 
    printf("1)INSERT_AT_BEGIN\n2)INSERT_AT_END\n3)INSERT_AT_MID\n4)DELETE_FROM_FRONT\n5)DELETE_FROM_END\n6)DELETE_FROM_MIDDLE\n7)DISPLAY\n8)count\n9)EXIT\n"); 
    printf("ENTER YOUR CHOICE:\n"); 
    scanf("%d",&cho); 
    switch(cho)
    {
        case 1:
        start = insert_begin(start); 
        break; 

        case 2:
        start = insert_end(start); 
        break; 

        case 3:
        start = insert_after(start); 
        break; 

        case 4:
        start = delete_begin(start); 
        break;

        case 5:
        start = delete_end(start); 
        break; 

        case 6:
        start = delete_middle(start); 
        break; 

        case 7:
        display(start); 
        break; 

        case 8:
        count(start); 
        break; 
    }
    }while(cho!=9); 
}