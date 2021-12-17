#include<iostream>
using namespace std;

struct node
{
    char data;
    struct node *next;
}*top=NULL;

void push(char key)
{
    node *t=new node;
    if(t==NULL)
    cout<<"Stack is full "<<endl;
    else
    {
        t->data=key;
        t->next=top;
        top=t;
    }
}

char pop()
{
    node *p=top;
    char x=-1;
    if(top==NULL)
    {
        cout<<"Stack is empty "<<endl;
    }
    else
    {
        top=top->next;
        x=p->data;
        delete p;
    }
    return x;
}
void display()
{
    node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int IsEmpty()
{
    if(top==NULL)
    return 1;
    else
    return 0;
}

int isBalance(char exe[])
{
    for(int i=0;exe[i]!='\0';i++)
    {
        if(exe[i]=='(')
        {
            push(exe[i]);
        }
        else if(exe[i]==')')
        {
            if(IsEmpty())
            return 0;
            pop();
        }
    }
    if(IsEmpty())
        return 1;
        else
        return 0;
}
int main()
{
    char exe[]="(((a+b)*(a+b)))";
    cout<<isBalance(exe);
    return 0;
}
