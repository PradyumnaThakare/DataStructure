#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*first=NULL;

void create(int arr[],int n)
{
    struct node *temp,*last;
    first =new node;
    first->data=arr[0];
    first->next=NULL;
    last =first;
    
    for(int i=1;i<n;i++)
    {
        temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void delele_node(int pos)
{
    if(pos==1)
    {
    node *p=first;
    first=first->next;
    delete p;
        
    }
    else
    {
        struct node *p=NULL,*q=first;
        for(int i=0;i<pos-1 && (q!=0);i++)
        {
            p=q;
            q=q->next;
        }
        if(p)
        {p->next=q->next;
        delete q;}
    }
    
}

void display()
{
    node *p=first;
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    int arr[]={2,3,45,5};
    create(arr,4);
    display();
    delele_node(2);
    cout<<endl;
    display();
    return 0;
}