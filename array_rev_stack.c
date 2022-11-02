#include<stdio.h>
#define size 5
struct stack
{
    int top; 
    int a[size]; 
}s1; 
int push(int val)
{
    if(s1.top==size-1)
    {
        printf("STACK OVERFLOW\n"); 
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
        printf("STACK UNDERFLOW!!\n"); 
    }
    else
    {
        temp=s1.a[s1.top]; 
        s1.top--; 
        return temp; 
    }
}
void main()
{
    int n,val,i;
    s1.top=-1; 
    printf("enter number of elements in array:\n"); 
    scanf("%d",&n); 
    int arr[n];
    printf("enter elements of array:\n"); 
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]); 
    }
    printf("orignal array is:\n"); 
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]); 
    }
    for(i=0;i<n;i++)
    {
        push(arr[i]); 
    }
    for(i=0;i<n;i++)
    {
        val=pop(); 
        arr[i]=val; 
    }
    printf("reversed array is:\n"); 
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]); 
    }
}