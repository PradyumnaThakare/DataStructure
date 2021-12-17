#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int value)
{
    struct node *t =new node;
    if(t==NULL)
    cout<<"Stack is full "<<endl;
    else
    {
        t->data=value;
        t->next=top;
        top=t;
    }
}

int top_ele()
 {
     node *p=top;
     int x;
     if(top==NULL)
     {
         return -1;
     }
     else
     {
         x=p->data;
     }
     return x;
 }
int pop()
{
    int value=-1;
    node *p=top;
    
    if(top==NULL)
    cout<<"Stack underFlow "<<endl;
    else
    {
        value=p->data;
        top=top->next;
        delete p;
    }
    return value;
}

int peep(int pos)
{
    int x=-1;
    node *p=top;
    for(int i=0;i<pos-1 && p!=NULL;i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    return p->data;
    else
    return -1;
    
}

void display()
{
    node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    cout<<pop();
    cout<<endl;
    cout<<top_ele();
}