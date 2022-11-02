#include<stdio.h>
#define size 9
int vis[size]; 
struct stack
{
    int a[size]; 
    int top; 
}s; 
struct node
{
    struct node *next; 
    int vertex; 
}; 
struct node *adj[size]; 
void push(int val)
{
    s.top++; 
    s.a[s.top]=val; 
}
int pop()
{
    int temp; 
    temp=s.a[s.top]; 
    s.top--; 
    return temp; 
}
struct node *creategraph(struct node *temp,int val)
{
    struct node *pnew=(struct node *)sizeof(struct node); 
    pnew->vertex=val; 
    pnew->next=NULL; 
    pnew->next=temp; 
    temp=pnew; 
    return temp; 
}
void dfs(int s)
{
    int p; 
    push(s); 
    p=pop(); 
    if(p!=0)
    printf("%d\n",p); 
    while(p!=0)
    {
        while(adj[p]!=NULL && vis[adj[p]->vertex]==0)
        {
            push(adj[p]->vertex);
            vis[adj[p]->vertex]=1;  
            adj[p]=adj[p]->next; 
        }
    p=pop(); 
    if(p!=0)
    printf("%d\n",p);
    }
}
void main()
{
    int nodes,edges,sp,ep,sv;
    struct node *hp; 
    s.top=-1; 
    printf("enter no. of edges:\n"); 
    scanf("%d",&edges); 
    printf("enter no. of nodes:\n"); 
    scanf("%d",&nodes);
    for(int i=0;i<size;i++)
    {
        adj[i]=NULL; 
    }
    for(int i=0;i<size;i++)
    {
        vis[i]=0; 
    }
    for(int i=1;i<=edges;i++)
    {
    printf("enter start point:\n"); 
    scanf("%d",&sp); 
    printf("enter end point:\n"); 
    scanf("%d",&ep);
    adj[sp]=creategraph(adj[sp],ep); 
    adj[ep]=creategraph(adj[ep],sp);
    }
    printf("Adjancy List:\n"); 
    for(int i=1;i<=size;i++)
    {
        hp=adj[i]; 
        printf("\n"); 
        while(hp!=NULL)
        {
            printf("%d\t",hp->vertex); 
            hp=hp->next; 
        }
    }
    printf("enter source vertex:\n"); 
    scanf("%d",&sv); 
    dfs(sv);
}
