// Complete initalization of arr with the help of linked list
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
}*first=NULL;

void insert(int index,int key)
{
    node *temp,*p;
    if(index==0)
    {
        temp=new node;
        temp->data=key;
        temp->next=first;
        first=temp;
    }
    else
    {
        p=new node;
        p=first;
        for(int i=0;i<index-1 && (p!=NULL);i++)
        {
            p=p->next;
        }
        temp=new node;
        temp->data=key;
        temp->next=p->next;
        p->next=temp;
    }
}
void display()
{
    node *p=new node;
    p=first;
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
        
    }
}

int main()
{
    insert(0,1);
    insert(1,4);
    insert(2,5);
    insert(3,6);
    insert(4,100);
    display();
    return 0;
}