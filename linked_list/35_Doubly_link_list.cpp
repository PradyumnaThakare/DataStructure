#include<iostream>
using namespace std;

struct node
{
   node *prev;
   int data;
   node *next;
}*first=NULL;

void create(int arr[],int n)
{
  node *temp,*last;
  last=new node;
  first=new node;
  first->prev=NULL;
  first->data=arr[0];
  first->next=NULL;
  last=first;

  for(int i=1;i<n;i++)
  {
    temp=new node;
    temp->data=arr[i];
    temp->next=last->next;
    temp->prev=last;
    last->next=temp;
    last=temp;
  }
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void insert(int index,int n)
{

  if(index==0)
  {
    node *temp=new node;
    temp->data=n;
    temp->next=first;
    temp->prev=NULL;
    first->prev=temp;
    first=temp;
  }
  else
  {
    node *temp=new node;
    node *p=first;
    for(int i=0;i<index;i++)
    {
      p=p->next;
    }
    temp->data=n;
    temp->next=p->prev->next;
    temp->prev=p->prev;
    p->prev->next=temp;
    p->prev=temp;
  }

}

void deleteEle(int index)
{
   node *p=first;
   if(index==1)
   {
     first=first->next;
     delete p;
   }
   else
   {
      for(int i=0;i<index-1;i++)
      {
        p=p->next;
      }
      p->prev->next=p->next;
      if(p->next!=NULL)
      p->next->prev=p->prev;
      delete p;
   } 
}

void rev()
{
  struct node *p=first;
  while(p!=0)
  {
    node *temp=p->next;
    p->next=p->prev;
    p->prev=temp;

    p=p->prev;
    if(p!=NULL && p->next==NULL)
    first=p;
  }
}
  

int main()
{
  int arr[]={10,20,30,40,50};
  create(arr,5);
  display(first);

  /*insert(0,100);
  display(first);
  deleteEle(1);
  display(first);
  deleteEle(4);
  display(first);*/

  rev();
  display(first);
  return 0;
}