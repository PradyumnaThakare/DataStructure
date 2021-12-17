#include<iostream>
using namespace std;

struct Queue 
{
    int fornt;
    int rear;
    int size;
    int *q;
};

void create(struct Queue *p,int n)
{
    p->size=n;
    p->fornt=-1;
    p->rear=-1;
    p->q=new int[p->size];
}

void enQueue(struct Queue *p,int n)
{
    if(p->rear==p->size-1)
    cout<<"Queue is Full "<<endl;
    else
    {
        p->rear++;
        p->q[p->rear]=n;
    }
}

int deQueue(struct Queue *p)
{
    int x=-1;
    if(p->fornt==p->rear)
    cout<<"Queue is empty "<<endl;
    else
    {
        p->fornt++;
        x=p->q[p->fornt];
    }
    return x;
}
void Display(struct Queue *p)
{
    for(int i=p->fornt+1;i<=p->rear;i++)
    {
        cout<<p->q[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    struct Queue q;
    create(&q,5);
    enQueue(&q,1);
    enQueue(&q,2);
    enQueue(&q,3);
    enQueue(&q,4);
    Display(&q);
    cout<<"deleted element : "<<deQueue(&q)<<endl;
    Display(&q);
    
}