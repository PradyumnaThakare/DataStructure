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

void rev()
{
   struct node*p=first,*temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        
        p=p->prev;
        
        if(p!=NULL && p->next==NULL)
        first=p;
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
    rev();
    display(first);
    return 0;
}