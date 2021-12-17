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
    first=new node;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=0;i<n;i++)
    {
        temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
    
}
node* move_head(struct node *head,int key)
{
    struct node*tail=NULL;
    while(head!=0)
    {
        if(key==head->data)
        {
            
           tail->next=head->next;
           head->next=first;
           first=head;
           return head;
        }
       tail=head;
       head=head->next;
    }
    return NULL;
}
int main()
{
   int arr[]={2,3,1000,5,6,0};
   create(arr,6);
   cout<<move_head(first,6);
  return 0;
}