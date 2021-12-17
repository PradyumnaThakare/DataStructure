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

void delete_ele(int index)
{
    if(index==1)
    {
        node *p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        if(p==head)
        {
            delete head;
            head=NULL;
        }
        else
        {p->next=head->next;
        delete head;
        head=p->next;}
    }
    else
    {
    node *p=head ,*q=NULL;
    for(int i=0;i<index-1 && p;i++)
    {
        q=p;
        p=p->next;
    }
    if(p)
    {
    q->next=p->next;
    delete p;
    }
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
    cout<<endl;
    delete_ele(1);
    display_circular_LL(head);
    return 0;
}