#include<iostream>
#include<cstring>
using namespace std;

struct Node
{
 char data;
 struct Node *next;
}*top=NULL;

 void push(char value)
 {
     Node *t=new Node;
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
     Node *p=top;
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
     Node *p=top;
     char x;
     if(top==NULL)
     {
         return -1;
     }
     return p->data;
 }
 
 int pre(char value)
 {
     if(value=='+'|| value=='-')
     return 1;
     else if(value=='*'|| value=='/')
     return 2;
     else
     return 0;
 }
 
 int Chek_operand(char x)
 {
     if(x=='+' || x=='-'||x=='*'||x=='/')
     return 0;
     else
     return 1;
 }
 char *IntoPost(char *infix)
 {
     int i=0;int j=0;
     char *postfix;
     int len=strlen(infix);
     postfix=new char[len+2];
     while(infix[i]!='\0')
     {
         if(Chek_operand(infix[i]))
         postfix[j++]=infix[i++];
         else
         {
             if(pre(infix[i])>pre(top->data))
             push(infix[i++]);
             else
             {
                 postfix[j++]=pop();
             }
         }
     }
     
     while(top!=NULL)
     postfix[j++]=pop();
     
     postfix[j]='\0';
     return postfix;
 }
 int main()
 {
    char i[50];
    cout<<"Enter string : ";
    cin.get(i,40);
     char *infix=i;
     push('#');
     char *postfix=IntoPost(infix);
     cout<<postfix;
 }
 /*
 
#include<iostream>

#include<cstring>

using namespace std;

class node

{

public:

   char data;

   node*next;

};

class stack

{

private:

   node*top;

public:

   stack();

   ~stack();

   void push(char x);

   char pop();

   char peek(int pos);

   char stackTop();

   int isEmpty();

   int isFull();

   void display();

};

stack::stack()

{

   top=NULL;

}

stack::~stack()

{

   node*p=top;

   while(top)

   {

      top=top->next;

      delete p;

      p=top;

   }

}

char stack::stackTop()

{

   if(top)

      return top->data;

   return -1;

}

int stack::isEmpty()

{

   return top?0:1;

}

int stack::isFull()

{

   node*t=new node;

   int r=t?0:1;

   delete t;

   return r;

}

void stack::push(char x)

{

   node*t=new node;

   if(t==NULL)

      cout<<"\nStack overflow!";

   else

   {

      t->data=x;

      t->next=top;

      top=t;

   }

}

char stack::pop()

{

   char x=-1;

   if(top==NULL)

      return x;

   node*p=top;

   x=p->data;

   top=top->next;

   delete p;

   return x;

}

char stack::peek(int pos)

{

   if(top==NULL)

      cout<<"Empty stack";

   node*p=top;

   for(int i=0;p!=NULL && i<(pos-1);i++)

   {

      p=p->next;

   }

   if(p)

      return p->data;

   else

      return -1;

}

void stack::display()

{

   node*p=top;

   while(p)

   {

      cout<<p->data<<" ";

      p=p->next;

   }

   cout<<endl;

}

int precedence(char x)

{

   if(x=='+'||x=='-')

      return 1;

   else if(x=='*'||x=='/')

      return 2;

   else if(x=='^')

      return 3;

   return 0;

}

bool isOperand(char x)

{

   if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')

      return false;

   else

      return true;

}

char* InToPost(char*infix)

{

   stack st;

   char*postfix=new char[strlen(infix)+1];

   int i,j;

   i=j=0;

   while(infix[i]!='\0')

   {

      if(isOperand(infix[i]))

      {

         postfix[j++]=infix[i++];

      }

      else

      {

         if(precedence(infix[i])>precedence(st.stackTop()))

         {

            st.push(infix[i++]);

         }

         else

         {

            postfix[j++]=st.pop();

         }

      }

   }

   while(!st.isEmpty())

   {

      postfix[j++]=st.pop();

   }

   postfix[j]='\0';

   return postfix;

}

int main()

{

   char *infix="a+b*c-d/e";

   cout<<InToPost(infix)<<endl;

   return 0;

} 
 */