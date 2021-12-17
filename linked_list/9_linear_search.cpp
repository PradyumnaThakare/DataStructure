#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first;

void create (int arr[],int n)
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
node* linear(struct node *p,int key)
{
    while(p!=0)
    {
        if(p->data==key)
        {return p;}
        p=p->next;
    }
    return NULL;
}
int main()
{
   int arr[]={2,3,1000,5,6,0};
   create(arr,6);
   cout<<linear(first,0);
  return 0;
}