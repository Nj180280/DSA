#include<stdio.h>
#include<string.h>
#define size 10
struct stack
{
    int a[size]; 
    int top; 
}s1; 
void push(char c)
{
    if(s1.top==size-1)
    {
        printf("STACK OVERFLOW\n"); 
    }
    else
    {
        s1.top++; 
        s1.a[s1.top]=c; 
    }
}
char pop()
{
    if(s1.top==-1)
    {
        printf("STACK UNDERFLOW!!\n"); 
    }
    else
    {
        return s1.top--; 
    }
}
void main()
{
    s1.top=-1;
    char exp[size],temp;
    int i,flag=1;  
    printf("enter any expression:\n"); 
    gets(exp); 
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=="{"||exp[i]=="["||exp[i]=="(")
        {
            push(exp[i]); 
        }
        if(exp[i]=="}"||exp[i]=="]"||exp[i]==")")
        {
            if(s1.top==-1)
            {
                flag=0; 
            }
            else
            {
                temp=pop();
                if(exp[i]=="}"&&(temp=="["||temp=="("))
                {
                    flag=0; 
                }
                if(exp[i]=="]"&&(temp=="{"||temp=="("))
                {
                    flag=0; 
                }
                if(exp[i]==")"&&(temp=="{"||temp=="["))
                {
                    flag=0; 
                }
            }
        }
    }
    if(s1.top>=0)
    {
        flag=0; 
    }
    if(flag==1)
    {
        printf("valid expresssion\n"); 
    }
    else
    {
        printf("invalid expression\n"); 
    }
}