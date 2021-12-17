#include<iostream>
#include<cstring>
using namespace std;

struct node
{
    char data;
    node *next;
}*top=NULL;

void push(char key)
{
    node *temp=new node;
    if(temp==NULL)
    {
        cout<<"Stack is full "<<endl;
    }
    else
    {
        temp->data=key;
        temp->next=top;
        top=temp;
    }
}

char pop()
{
    char x;
    
    if(top==NULL)
    {
        cout<<"Stack is empty "<<endl;
    }
    else
    {
        node *p=top;
        x=p->data;
        top=top->next;
        delete p;
    }
    return x;
}

char Topele()
{
    node *p=top;
    if(top==NULL)
    {
        return 0;
    }
    return p->data;
}

int isOperand(char key)
{
    if(key=='+'||key=='-'||key=='/'||key=='*'||key=='('||key==')'||key=='^')
    return 0;
    else
    return 1;
}

int INpre(char key)
{
    if(key=='+'||key=='-')
    return 2;
    else if(key=='*'||key=='/')
    return 4;
    else if(key=='^')
    return 5;
    else if(key=='(')
    return 0;
    else
    return -1;
}
int OUTpre(char key)
{
    if(key=='+'||key=='-')
    return 1;
    else if(key=='*'||key=='/')
    return 3;
    else if(key=='^')
    return 6;
    else if(key=='(')
    return 7;
    else if(key==')')
    return 0;
    else
    return -1;
}
char *infixTOpostfix(char *infix)
{
    char *postfix;
    int len=strlen(infix);
    postfix=new char[len+2];
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
        else
        {
            if(top->data==-1 || OUTpre(infix[i])>INpre(top->data))
            {
                push(infix[i++]);
            }
            else 
            {if(OUTpre(infix[i])==INpre(top->data))
            {
                pop();
                i++;
            }
            else
            {
                postfix[j++]=pop();
            }
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
     char *postfix=infixTOpostfix(infix);
     cout<<postfix;
    return 0;
}