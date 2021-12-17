#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[],int n)
{
    struct node *temp,*last;
    first =new node;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++)
    {
        temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}
void insert(int index, int key)
{
    node *p=new node;
    p=first;
    if(index==0)
    {
        node *temp=new node;
        temp->data=key;
        temp->next=first;
        first=temp;
    }
    else
    {
        for(int i=0;i<index-1 && (p!=NULL);i++)
        {
            p=p->next;
        }
        if(p!=NULL)
       { node *temp=new node;
        temp->data=key;
        temp->next=p->next;
        p->next=temp;}
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
   int arr[]={2,3,1000,5,6,0};
   create(arr,6);
   insert(1000,69);
   display();
  return 0;
}