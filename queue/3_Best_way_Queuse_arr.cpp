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
    p->fornt=0;
    p->rear=0;
    p->q=new int[p->size];
}

void enQueue(struct Queue *p,int n)
{
    if((p->rear+1)%p->size==p->fornt)
    cout<<"Queue is fULL "<<endl;
    else
    {
        p->rear=(p->rear+1)%p->size;
        p->q[p->rear]=n;
    }
}

int deQueue(struct Queue *p)
{
    int x=-1;
    if((p->fornt)==p->rear)
    cout<<"Queue is empty "<<endl;
    else
    {
        
        p->fornt=(p->fornt+1)%p->size;
        x=p->q[p->fornt];
    }
    return x;
}
void Display(struct Queue *p)
{
    int i=p->fornt+1;
    do
    {
        cout<<p->q[i]<<" ";
        i=(i+1)%p->size;
    }while(i!=(p->rear+1)%p->size);
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