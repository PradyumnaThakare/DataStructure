//Inserting in a sorted linklist
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
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

void insert_sort_position(int x)
{
    struct node*p=first;
    struct node*q=NULL;
    
    struct node *temp=new node;
    temp->data=x;
    temp->next=NULL;
    
    if(first==NULL)
    {
        first=temp;
    }
    else
 {
 while(p && p->data<x)
 {
 q=p;
 p=p->next;
 }
 if(p==first)
 {
 temp->next=first;
 first=temp;
 }
 else
 {
 temp->next=q->next;
 q->next=temp;
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
    insert(4);
    insert(5);
    insert(7);
    insert_sort_position(6);
    display();
    return 0;
}