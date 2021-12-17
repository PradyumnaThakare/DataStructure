//This method would be used to create linklist

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*first=NULL,*last=NULL;

void insert(int x)
{
    node *temp=new node ;
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
    insert(4);
    insert(5);
    insert(6);
    display();
    return 0;
}