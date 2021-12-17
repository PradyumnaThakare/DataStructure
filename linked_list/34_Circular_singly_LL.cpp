//Circular singly Linked list
#include<iostream>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*head=NULL,*head2=NULL,*last=NULL;

void create(int arr[],int n)
{
  node *last=new node;
   head=new node;
  node *temp;

  head->data=arr[0];
  head->next=head;
  last=head;

  for(int i=1;i<n;i++)
  {
    temp=new node;
    temp->data=arr[i];
    temp->next=last->next;
    last->next=temp;
    last=temp;
  }
}

void display(struct node *p)
{
    do
    {
      cout<<p->data<<" ";
      p=p->next;
    }while(p!=head)   ;
    cout<<endl;
    
}

void count(struct node *p)
{
  int count=0;
  do 
  {
    count++;
   p=p->next; 
  }while(p!=head);
  cout<<"Total number of node : "<<count<<endl;
}

void sum(struct node *p)
{
   int sum=0;
   do
   {
     sum=sum+p->data;
     p=p->next;
   } while (p!=head);
   cout<<"Sum of the nodes : "<<sum<<endl;
}

void max(struct node *p)
{
    int max=-10000;
    do
    {
      if(p->data>max)
      {
        max=p->data;
      }
      p=p->next;
    } while (p!=head);
    cout<<"Max element in the node is : "<<max<<endl;
}

node* Linear_move_to_head(struct node*p,int key)
{
    node *q=NULL,*t=head;
    do
    {
      /* code */
      q=p;
      if(p->data==key)
      {
        cout<<p->data<<" ";
        q->next=p->next;
        p->next=head->next;
        head=p;
        p->next->next=head;
        return p;
      }
      p=p->next;
    } while (p!=head);
    return 0;
    
}

void insert(int index,int key)
{
 
  if(index==0)
  {
    struct node *p=head;
    node *temp=new node;
    temp->data=key;
    temp->next=head;
     if(head==NULL)
     {
       head=temp;
       head->next=head;
     }
     while (p->next!=head)
     {
       p=p->next;
     }
    p->next=temp;
    head=temp;
    
  }
  else
  {
      struct node *p=head;
      for(int i=0;i<index-1;i++)
      {
        p=p->next;
      }
      {
      node *temp=new node;
      temp->data=key;
      temp->next=p->next;
      p->next=temp;
      }
  }
}
/*
void insert_last(int key)
{
  node *temp=new node;
  temp->data=key;
  temp->next=head2;
  if(head2==NULL)
  {
    head2=last=temp;
  }
  else
  {
   /* node *p=head2;
    while (p->next!=head2)
    {
      p=p->next;
    }*/
    //last->next=temp;
    //last=temp;
    //temp->next=head2;
 // }
//}   

void insertion_sort(struct node *p,int x)
{
    if(x<p->data)
    {
      while(p->next!=head)
      {
        p=p->next;
      }
      node *temp=new node;
      temp->data=x;
      temp->next=head;
      p->next=temp;
      head=temp;
    }
    else
    {
      node *q=NULL;
      node *temp=new node;
      temp->data=x;
      do
      {
      q=p;
      p=p->next;
      }while(p!=head && p->data<x);
        temp->next=q->next;
        q->next=temp;
    }
}

void delete_ele(int index)
{
    if(index==1)
    {
       node *q=head->next;
       node *p=head;
       while (p->next!=head)
       {
          p=p->next;
       }
      p->next=q;
      delete head;
      head=p->next;
    }
    else
    {
      node *p=head;
      for(int i=0;i<index-1;i++)
      {
          p=p->next;
      }
      node *q=p->next;
      q->next=p->next;
      delete q;
    }
}
void Dubli_dele()
{
   node *q=head;
   node *p=head->next;
   do
   {
     /* code */
    
     if(q->data!=p->data)
     {
       q=p;
       p=p->next;
     }
     else
     {
        q->next=p->next;
        delete p;
        q=p->next;
     }
   } while (p!=head);
}

int main()
{
  int arr[]={3,5,5,8,8,8};
  create(arr,5);
  display(head);
  count(head);
  sum(head);
  max(head);
  //cout<<"Present at  : "<<Linear_move_to_head(head,10)<<endl;
  //cout<<"Present at  : "<<Linear_move_to_head(head,100)<<endl;

 // insert(5,5);
  //display(head);

 /* insert_last(1);
  insert_last(2);
  insert_last(3);
  insert_last(4);

  display(head2);*/

 /* insertion_sort(head,70);
  display(head);

  delete_ele(1);
  display(head);
*/
  Dubli_dele();
  display(head);
  return 0;
}