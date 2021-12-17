#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    node *t=new node;
    if(t==NULL)
    cout<<"Queue is full "<<endl;
    else
    {
             t->data=x;
            t->next=NULL;
        if(front==NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}
int deQueue()
{
    int x=-1;
    if(front==NULL)
    cout<<"Queue empty "<<endl;
    else
    {
        node *p=front;
        x=p->data;
        front=front->next;
        delete p;
    }
    return x;
}

void diplay()
{
    node *p=front;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    enqueue(10);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    diplay();
    cout<<deQueue();
    
    return 0;
}