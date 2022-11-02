#include<stdio.h>
#include<stdlib.h>
struct ll_node
{
    int data; 
    struct ll_node *next; 
}; 
struct ll_node *start=NULL;
struct ll_node insert_at_begin(struct ll_node *start)
{
    int val; 
    struct ll_node *pnew=((struct ll_node *)malloc(sizeof(struct ll_node))); 
    struct ll_node *ptr; 
    ptr=start; 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    pnew->data=val; 
    pnew->next=start; 
    start=pnew; 
    return start; 
}
struct ll_node insert_at_end(struct ll_node *start)
{
    int val; 
    struct ll_node *pnew=((struct ll_node *)malloc(sizeof(struct ll_node))); 
    struct ll_node *ptr; 
    ptr=start; 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    pnew->data=val; 
    while(ptr->next!=NULL) //we have initialized ptr to start here
    {
        ptr=ptr->next; 
        ptr->next=pnew;
    }
    return start; 
}
struct ll_node insert_after(struct ll_node *start)
{
    int num,val; 
    struct ll_node *prev; 
    struct ll_node *ptr; 
   struct ll_node *pnew=((struct ll_node *)malloc(sizeof(struct ll_node)));  
    ptr=start; 
    prev=ptr; 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    printf("enter value after which insertion needs to be done:\n"); 
    scanf("%d",&num);
    pnew->data=val; 
    while(prev->next!=num)
    {
        prev=ptr;
        ptr=ptr->next; 
    }
    prev->next=pnew; 
    pnew->next=ptr; 
    return start;
}
struct ll_node insert_before(struct ll_node *start)
{
    int num,val; 
    struct ll_node *prev;
    struct ll_node *ptr; 
    struct ll_node *last; 
   struct ll_node *pnew=((struct ll_node *)malloc(sizeof(struct ll_node))); 
    ptr=start; 
    prev=ptr; 
    last=prev; 
    printf("enter value to be inserted:\n"); 
    scanf("%d",&val);
    printf("enter value before which insertion needs to be done:\n"); 
    scanf("%d",&num);
    pnew->data=val; 
    while(ptr->data!=num)
    {
        prev=ptr; 
        ptr=ptr->next; 
    }
    prev->next=pnew; 
    pnew->next=ptr; 
    return start; 
}
struct ll_node delete_at_begin(struct ll_node *start)
{
    struct ll_node *ptr; 
    ptr=start; 
    start=start->next; 
    free(ptr); 
    return start; 
}
struct ll_node delete_end(struct ll_node *start)
{
    struct ll_node *ptr; 
    struct ll_node *prev; 
    ptr=start; 
    prev=ptr; 
    while(ptr->next!=NULL)
    {
        prev=ptr; 
        ptr=ptr->next; 
    }
    prev->next=NULL;
    free(ptr); 
    return start; 
}
struct ll_node delete_node(struct ll_node *start)
{
    struct ll_node *ptr; 
    struct ll_node *prev; 
    ptr=start; 
    prev=ptr; 
    printf("enter value after which deletion needs to be done:\n"); 
    scanf("%d",&num);
    while(ptr->data!=num)
    {
        prev=ptr; 
        ptr=ptr->next; 
    }
    ptr=ptr->next; 
    prev->next->next=ptr; 
    free(ptr); 
    return start; 
}
struct ll_node display(struct ll_node *start)
{
    struct ll_node *ptr; 
    ptr=start; 
    printf("linked list is:\n");
    while(ptr->next!=NULL)
    {
        ptr=ptr->next; 
        printf("%d\t",ptr->data); 
    }
}
struct ll_node *count(struct ll_node *start)
{
    struct ll_node *ptr; 
    int c=0;
    ptr=start; 
    while(ptr->next!=NULL)
    {
        c++; 
        ptr=ptr->next; 
    }
    printf("number of nodes are %d\n",c); 
}
struct ll_node *sort(struct ll_node *start)
{
    int temp; 
    struct ll_node *ptr1,*ptr2; 
    ptr1=start;
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next; 
            while(ptr2!=NULL)
            {
                if(ptr1->data>ptr2->data)
                {
                temp=ptr1->data; 
                ptr1->data=ptr2->data; 
                ptr2->data=temp; 
                }
                ptr2=ptr2->next;
            }
        ptr1=ptr1->next;
    }
    return start;
}
int main()
{
    int cho; 
    do
    {
    printf("MENU IS AS FOLLOWS:\n"); 
    printf("\n1)insert at beginning\n2)insert at end\n3)insert after node\n4)insert before node\n5)delete from beginning\n6)delete from end\n7)delete node\n8)display\n9)count\n10)sort\n11)EXIT\n"); 
    printf("enter choice\n"); 
    scanf("%d",&cho); 
    switch(cho)
    {
        case 1:
        start = insert_at_begin(start); 
        display(start); 
        break; 

        case 2:
        start = insert_at_end(start); 
        display(start); 
        break;

        case 3:
        start = insert_after(start); 
        display(start); 
        break;

        case 4:
        start = insert_before(start); 
        display(start); 
        break;

        case 5:
        start = delete_at_begin(start); 
        display(start); 
        break;

        case 6:
        start = delete_end(start); 
        display(start); 
        break;

        case 7:
        start = delete_node(start); 
        display(start); 
        break;

        case 8:
        start=display(start); 
        break; 

        case 9:
        start = count(start); 
        display(start); 
        break;

        case 10:
        start = sort(start); 
        display(start); 
        break;
    }
    }while(cho!=11);
}