#include<iostream>
using namespace std;
 struct node
 {
     char data;
     node *next;
 }*top=NULL;
 
 void push(char value)
 {
     node *t=new node;
     if(t==NULL)
     {
         cout<<"Full "<<endl;
     }
     else
     {
         t->data=value;
         t->next=top;
         top=t;
     }
 }
 char pop()
 {
     node *p=top;
     char x;
     if(top==NULL)
     {
         cout<<"Empty "<<endl;
     }
     else
     {
         top=top->next;
         x=p->data;
         delete p;
     }
     return x;
 }
 
  char top_ele()
 {
     node *p=top;
     char x;
     if(top==NULL)
     {
         return -1;
     }
     return p->data;
 }
 int isBalance(char arr[])
 {
     char x;
    for(int i=0;arr[i]!='\0';i++)
    {
        if(arr[i]=='{'||arr[i]=='('||arr[i]=='[')
        {
            push(arr[i]);
        }
        else if(arr[i]=='}'||arr[i]==')'||arr[i]==']')
        {
            if (top==NULL)
            return 0;
            
            else if(arr[i]==top_ele()+1||arr[i]==top_ele()+2)
            pop();
            
            else
            return 0;
        }
    }
    if(top==NULL)
        return 1;
        else
        return 0;
 }
 
 int main()
 {
     char arr[50];
     cin>>arr;
    if(isBalance(arr)==1)
    cout<<"Mathched ";
    else
    cout<<"Not Mathched ";
 }