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
void delete_ele(int index)
{
    if(index==1)
    {
        node *p=first;
        first=first->next;
        delete p;
        if(first!=NULL)
        {
            first->prev=NULL;
        }
    }
    else{
    node *p=first;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    p->prev->next=p->next;
    if(p->next!=NULL)
    {
        p->next->prev=p->prev;
    }
    delete p;
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
    delete_ele(1);
    display(first);
    return 0;
}