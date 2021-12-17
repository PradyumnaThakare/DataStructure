#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void create(int arr[] ,int n)
{
    node *temp,*last;
    first=new node;
    first->data=arr[0];
    first->prev=first->next=NULL;
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

void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void length()
{
    struct node *p=first;
    int len=0;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    cout<<"Total length : "<<len<<endl;
}

int main()
{
    int arr[]={10,20,30,40,50};
    create(arr,5);
    length();
    display(first);
    return 0;
}