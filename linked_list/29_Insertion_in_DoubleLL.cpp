#include<iostream>
using namespace std;

struct node 
{
    node *prev;
    int data;
    node *next;
}*first=NULL;

void create(int arr[],int n)
{
    node *temp,*last;
    first=new node;
    first->data=arr[0];
    first->next=first->prev=NULL;
    last=first;
    
    for(int i=1;i<n;i++)
    {
        temp=new node;
        temp->data=arr[i];
        temp->next=last->next;
        temp->prev=last;
        last->next=temp;
        last=temp;
    }
}

void insert(int index,int key)
{
    if(index==0)
    {
        node *temp=new node;
        temp->data=key;
        temp->prev=NULL;
        temp->next=first;
        first->prev=temp;
        first=temp;
    }
    else
    {
    node  *p=first,*q;
    
    for(int i=0;i<index-2 && p;i++)
    {
        p=p->next;
    }
    if(p)
    {
    q=p->next;
    node * temp=new node;
    temp->data=key;
    temp->next=q->next;
    temp->prev=q;
    p->prev=temp;
    q->next=temp;
    }
    }
}
void display(struct node *p)
{
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    int arr[]={10,20,30,40,50};
    create(arr,5);
    display(first);
    insert(0,0);
    display(first);
    return 0;
}