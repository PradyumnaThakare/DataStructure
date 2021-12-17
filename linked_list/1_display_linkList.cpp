//Creating and displaying the list
#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
}*first=NULL;//global Data type

void create(int arr[],int n)
{
    first=new node;
    struct node *temp,*last;
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
void display(struct node*p)
{
  while(p!=0)
  {
    cout<<p->data<<" ";
    p=p->next;
  }
}
int main()
{
   int arr[]={2,3,4,5,6};
   create(arr,5);
   cout<<"Displaying the elements in ll "<<endl;
   display(first);
  return 0;
}