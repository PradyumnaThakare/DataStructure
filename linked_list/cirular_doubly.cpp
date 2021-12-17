#include<iostream>
using namespace std;

struct node
{
  node *prev;
  int data;
  node *next;
}*head=NULL;

void create(int arr[],int n)
{
    node *temp,*last;
    last=new node;
    head=new node;
    head->data=arr[0];
    head->next=head;
    head->prev=head;
    last=head;

    for(int i=1;i<n;i++)
    {
       temp=new node;
       temp->data=arr[i];
       temp->next=last->next;
       temp->prev=last;
       last->next=temp;;
       last=temp;
    }
}

void display(struct node *p)
{
  do
  {
    /* code */
    cout<<p->data<<" ";
    p=p->next;
  } while (p!=head);
  cout<<endl;
  
}

void insert(int index,int key)
{

  if(index==0)
  {
     node *temp=new node;
     temp->data=key;
     temp->next=head;
     temp->prev=head->prev;
     head=temp;
     head->prev=temp;
  }
  node *p=head;
  for(int i=0;i<index-1;i++)
  {
    p=p->next;
  }
  node *temp=new node;
  temp->data=key;
  temp->next=p->prev->next;
  temp->prev=p->prev;
   p->prev->next=temp;
  p->prev=temp;
 
}
int main()
{
  int arr[]={10,20,30,40,50};
  create(arr,5);
  display(head);

  insert(0,100);
  display(head);
  return 0;
}