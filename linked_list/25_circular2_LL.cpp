//circular LL using recursion
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
}*head=NULL;

void create(int arr[],int n)
{
    head=new node;
    node *temp,*last;
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


void display_circular_LL(struct node *p)
{

    
        cout<<p->data<<" ";
        p=p->next;
        if(p!=head)
        {
            display_circular_LL(p);
        }
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    create (arr,6);
    display_circular_LL(head);
    return 0;
}