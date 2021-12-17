#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first;

void create (int arr[] ,int n)
{
    struct node *temp,*last;
    first =new node;
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
int max(struct node *p)
{
    if(p==0)
    {
        return -1000;
    }
    int finaloutput=max(p->next);
    if(finaloutput>p->data)
    return finaloutput;
    else
    return p->data;
}
int main()
{
   int arr[]={2,3,4,5,6};
   create(arr,5);
   cout<<"Max element "<<endl;
 cout<< max(first);
  return 0;
}