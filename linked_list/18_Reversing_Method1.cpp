#include<iostream>
using namespace std;
// Method 1-> Revesing the ll by (reversing the elements)
struct node
{
    int data;
    node *next;
}*first=NULL,*last=NULL;

void insert(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->next=NULL;
    
    if(first==NULL)
    {
        first=last=temp;
    }
    else
    {
        last->next=temp;
        last=temp;
    }
}

void rev()
{
    node *p=first;
    int arr[10];
    int i=0;
    while(p!=0)
    {
        arr[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;i--;
    while(p!=0)
    {
        p->data=arr[i];
        p=p->next;
        i--;
    }
}
void display()
{
    node *p=first;
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    cout<<endl;
    rev();
    display();
    return 0;
}