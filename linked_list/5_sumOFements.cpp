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
    for(int i=1;i<n;i++)
    {
        temp=new node;
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void display(struct node *p)
{
    if(p==NULL)
    {
        return ;
    }
    cout<<p->data<<" ";
    display(p->next);
    
}

void sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum=sum+(p->data);
        p=(p->next);
    }
    cout<<"Sum of the elements is : "<<sum;
}
int main()
{
   int arr[]={2,3,4,5,6};
   create(arr,5);
   cout<<"Displaying the elements in ll "<<endl;
   display(first);
   cout<<endl;
   sum(first);
  return 0;
}