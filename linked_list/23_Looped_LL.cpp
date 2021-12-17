#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
}*first=NULL;

void create(int arr[],int n)
{
    first=new node;
    node *temp,*last;
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

int isLoop(struct node *f)
{
    struct node *p,*q;
    p=q=f;
    
    do
    {
        p=p->next;
        q=q->next;
        q=(q!=NULL)?q->next:NULL;
    }while((p!=NULL && q!=NULL) && (p!=q));
    
    if(p==q)
    return 1;
    else
    return 0;
}

void display(struct node *p)
{
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    struct node *t1,*t2;
    
    int arr[]={1,2,3,4,5};
    create(arr,5);
    
   /* t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    */
    
    if(isLoop(first)==1)
    cout<<"Loop linked list "<<endl;
    else
    cout<<"Linear linked List";
    return 0;
}