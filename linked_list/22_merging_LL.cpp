#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int arr[],int n)
{
    first=new node;
    node *temp,*last;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++)
    {
        temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void create2(int arr[],int n)
{
    second=new node;
    node *temp,*last;
    second->data=arr[0];
    second->next=NULL;
    last=second;
    
    for(int i=1;i<n;i++)
    {
        temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void merge(struct node *p, struct node *q)
{
    node *last=NULL;
    if(first->data<second->data)
    {
        third=last=first;
        first=first->next;
        last->next=0;
    }
    else
    {
        third=last=second;
        second=second->next;
        last->next=0;
    }
    while(first!=NULL && second!=NULL)
    {
        if(first->data<second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=0;
        }
        else
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=0;
        }
    }
    if(first!=0)
    {
        last->next=first;
    }
    else
    {
        last->next=second;
    }
}

void display(struct node *p)
{
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    create(arr,5);
    display(first);
    cout<<endl;
    
    int arr2[]={5,6,7,8,9};
    create2(arr2,5);
    display(second);
    
    merge(first ,second);
    cout<<endl;
    display(third);
    
    return 0;
}