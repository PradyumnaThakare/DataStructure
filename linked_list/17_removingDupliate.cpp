
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*first=NULL,*last=NULL;

void insert(int x)
{
    struct node * temp=new node;
    temp->data=x;
    temp->next=NULL;
    
    if(first==NULL)
    {
        first=last=temp;
    }
    else
    {
        last->next=temp;
        last=temp;
    }
}

void duplicate()
{
    node *p=first;
    node *q=first->next;
    
    while(q!=0)
    {
        if(p->data==q->data)
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
        else
        {
            p=q;
            q=q->next;
        }
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
    insert(3);
    insert(5);
    insert(5);
    insert(8);
    insert(8);
    insert(8);
    display();
    cout<<endl;
    duplicate();
    display();
    cout<<endl;
    
    
}