#include<iostream>
using namespace std;

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

int check_sorted()
{
    struct node *p=first;
    int x=-10000;
    while(p!=0)
    {
        if(p->data>x)
        {
            x=p->data;
            p=p->next;
        }
        else
        {
            return 0;
            
        }
    }
    return 1;
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
    insert(8);
    insert(10);
    insert(16);
    display();
    cout<<endl;
    if(check_sorted())
    cout<<"Sorted";
    else
    cout<<"Not soreted ";
    
}