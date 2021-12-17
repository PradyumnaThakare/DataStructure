//Reversing using recursion 
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*first=NULL,*last=NULL;

void insert(int x)
{
    node *temp = new node;
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

void rev(node *p,node *q)
{
    if(p!=NULL)
    {
        rev(p->next,p);
        p->next=q;
    }
    else
    {
        first=q;
    }
}
void display()
{
    node *p=first;
    while(p!=0)
    {
        cout<<p->data<<" ";
       p= p->next;
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
    rev(first,NULL);
    display();
    return 0;
}