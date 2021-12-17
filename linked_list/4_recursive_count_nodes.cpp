#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL;

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
void display(struct node *p)
{
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int node_count(struct node *p)
{
   
    if(p==0)
    {
        return 0;
    }
    else
    {
        
        return node_count(p->next)+1;
    }
}

int main()
{
   int arr[]={2,3,4,5,6};
   create(arr,5);
   cout<<"Displaying the elements in ll "<<endl;
    display(first);
   cout<<"Total node_count : "<<node_count(first);
  return 0;
}