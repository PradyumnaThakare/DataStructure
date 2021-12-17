#include<iostream>
using namespace std;

struct stack 
{
    int top;
    int size;
    int *s;
};

void create (struct stack *st)
{
    cout<<"Enter the size of the stack : ";
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size];
}

void display(struct stack st)
{
    cout<<"Displaying elements of stack : "<<endl;
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.s[i]<<" ";
    }
}

void push(struct stack *st ,int value)
{
    if(st->top==st->size-1)
    {
        cout<<"Stack overflow "<<endl;
    }
    else
    {
        st->top++;
        st->s[st->top]=value;
    }
}

int pop(struct stack *st)
{
    int value=-1;
    if(st->top==-1)
    {
         cout<<"Stack underoverflow "<<endl;
    }
    else
    {
        value=st->s[st->top];
        st->top--;
    }
    
    return value;
    
}

int peek(struct stack st,int pos)
{
    int x;
    int index=(st.top+1)-pos;
    if(index<0)
    {
        cout<<"Invalid "<<endl;
    }
    else
    {
        x=st.s[st.top];
    }
    return x;
}

int stackTop(struct stack st)
{
    if(st.top==-1)
    return -1;
    else
    return st.s[st.top];
}

int IsEmpty(struct stack st)
{
    if(st.top==1)
    return 1;
    else
    return 0;
}
int IsFull(struct stack st)
{
    if(st.top==st.size-1)
    return 1;
    else
    return 0;
}

int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
   // push(&st,60);
   cout<<peek(st,1);
    display(st);
    
    return 0;
}