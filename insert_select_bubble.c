#include<stdio.h>
void select_sort(int a[10],int n) //selection sort
{
    int t; 
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[j]; 
                a[i]=a[j]; 
                a[j]=temp;
            }
        }
    }
}
void bubble_sort(int a[10],int n) //bubble sort
{
    int t,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j]; 
                a[j]=a[j+1]; 
                a[j+1]=temp; 
            }
        }
    }
}
void insert_sort(int a[10],int n) //insert sort 
{
    int nv,j; 
    for(int i=1;i<n;i++)
    {
        nv=a[i]; 
        for(j=i;(j>0)&&(a[j-1]>nv);j--)
        {
            a[j]=a[j-1];
        }
        a[j]=nv;
    }
}
void quick_sort(int a[10],int first,int last)
{
    int i,j,pivot,temp; 
    if(first<last)
    {
        pivot=first; 
        i=first; 
        j=last; 
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
            {
                i++; 
            }
            while(a[j]>a[pivot])
            {
                j--; 
            }
            if(i<j)
            {
                temp=a[i]; 
                a[i]=a[j]; 
                a[j]=temp; 
            }
        }
        temp=a[pivot]; 
        a[pivot]=a[j]; 
        a[j]=temp; 
        quick_sort(a,first,j-1); 
        quick_sort(a,j+1,last); 
    }
}