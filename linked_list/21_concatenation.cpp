#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
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

void merge()
{
    node *p=first,*q=second;
    while(p!=0);
    {
        p=p->next;
    }
    p->next=q;
    second=NULL;
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
    int arr2[]={6,7,8,9,10};
    create2(arr2,5);
    display(second);
    cout<<endl;
    merge();
    display(first);
    return 0;
}