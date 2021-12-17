#include<iostream>
using namespace std;
// Method 2-> Revesing the ll by (reversing the links)
struct node
{
    int data;
    node *next;
}*first=NULL,*last=NULL;

void insert(int x)
{
    node *temp=new node;
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

void rev()
{
    node *p=first,*q=NULL,*r=NULL;
    while(p!=0)
    {
    r=q;
    q=p;
    p=p->next;
    
    q->next=r;
    }
    
    first=q;
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
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    cout<<endl;
    rev();
    display();
    return 0;
}