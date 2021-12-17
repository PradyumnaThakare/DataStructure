#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node *next;

};
class stack
{
  private:
  node *top;
  public:
  stack()
  {
    top=NULL;
  }
  void push(int);
  int pop();
  void display();
  int peek(int);
};

void stack::push(int value)
{
    node *t=new node;
    if(t==NULL)
    cout<<"Stack is full"<<endl ;
    else
    {
      t->data=value;
      t->next=top;
      top=t;
    }
}

int stack::pop()
{
  node *p=top;
  int x=1;
  if(top==NULL)
  {
      cout<<"Stack is Empty "<<endl;
  }
  else
  {
      top=top->next;
      x=p->data;
      delete p;
  }
  return x;
}
int stack::peek(int pos)
{
  node *p=top;
  for(int i=0;i<pos-1 && p!=NULL;i++)
  {
    p=p->next;
  }
  if(p!=NULL)
  return p->data;
  else
  return -1;
}

void stack::display()
{
  node *p=new node;
  p=top;
  while(p!=NULL)
  {
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<endl;
}
int main()
{
  stack st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.display();
  cout<<st.pop();
 
  return 0;
}