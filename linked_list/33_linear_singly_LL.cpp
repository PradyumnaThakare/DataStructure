//Linked singly linked list

#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL,*second=NULL,*last2=NULL,*third=NULL;

void create(int arr[],int n)//Creating linked-List using arrays
{
    struct node *temp,*last;
    last=new node;
    first=new node;
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

void display(struct node *p)//display using while loop
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void display_recusive(struct node *p)//display using recursion 
{
    if(p==NULL)
    {
       return;
    }
    cout<<p->data<<" ";
    return display_recusive(p->next);
    cout<<endl;
}

void rev_display_recursion(struct node *p)//recursive display of LL in rev order 
{
    if(p!=NULL)
    {
        rev_display_recursion(p->next);
        cout<<p->data<<" ";
    }
    
}

void count ( struct node *p) //Counting total no of nodes
{
    cout<<endl;
    int count=0;
    while(p!=0)
    {
        count++;
        p=p->next;
    }
    cout<<"ToTAL no. of nodes : "<<count<<endl;
}

int count_revcursive(struct node *p)//recursive Counting total no of nodes
{
    static int count=0;
    if(p==NULL)
    {
        return count;
    }
    
        count++;
       return count_revcursive(p->next);
}

void sum(struct node *p)//Sum of all the nodes elements
{
    int sum=0;
    while(p!=0)
    {
        sum=sum+p->data;
        p=p->next;
    }
    cout<<"Sum : "<<sum<<endl;
}

int sum_recur(struct node *p)//recursive Sum of all the nodes elements
{
    static int sum=0;
    if(p==0)
    {
        return sum;
    }
    return sum_recur(p->next)+p->data;
}

int max(struct node*p)//Finding max elements
{
    int max=-100000;
    while(p!=0)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
int max_recur(struct node *p)//Finding max elements using recursion 
{
    static int max=-100000;
    if(p==0)
    {
        return max;   
    }
    if(p->data>max)
        {
            max=p->data;
        }
        return max_recur(p->next);
}

node* linear_search_move_to_head(struct node *p,int key)// Improved Linear search
{
    node *q=NULL;
    while(p!=0)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void insert(int index,int key)
{
    if(index==0)
    {
    
        node *temp=new node;
        temp->data=key;
        temp->next=first;
        first=temp;
    }
    else
    {
        node *p=first;
        for(int i=0;i<index-1 && p!=NULL;i++)
        {
            p=p->next;
        }
        if(p)
        {
            node *temp=new node;
            temp->data=key;
            temp->next=p->next;
            p->next=temp;
        }
    }
}

void insert_last(int key)
{
     node *temp=new node;
     temp->data=key;
     temp->next=NULL;
   if(second==NULL)
   {
     second=last2=temp;
   }
   else
   { 
     last2->next=temp;
     last2=temp;
   }
    
}
void insert_in_a_sorted_ll(int x)
{
  node *t=new node;
  node *p=first;
  t->data=x;
  t->next=NULL;
   if(x<p->data)
   {
      t->next=first;
      first=t;
   }
   else
   {
     node *q=NULL;
     while(p!=NULL && p->data<x)
     {
       q=p;
       p=p->next;
     }
     t->next=q->next;
     q->next=t;
   }
}


void delete_ele(struct node *p,int index)
{
    if(index==1)
    {
      first=first->next;
      delete p;
    }
    else
    {
      for(int i=0;i<index-1 && p;i++)
      {
          p=p->next;
      }
      if(p)
      {
      node *q=p->next;
      p->next=q->next;
      delete q;
      }
    }
}

void revmove_dubli(struct node *p)
{
    node*q=p->next;
    while(q!=NULL )
    {
      if(p->data!=q->data)
      {
        p=q;
        q=q->next;
      }
      else
      {
         if(p->data==q->data)
         {
           p->next=q->next;
           delete q;
           q=p->next;
         }
      }
  }
}

int check_sorted(struct node *p)
{
    int temp=-10000;
    while(p!=0)
    {
      if(p->data>temp)
      {
          temp=p->data;
      }
      else
      {
        return 0;
      }
      p=p->next;
    }
    return 1;
}

void rev(struct node * r)
{
  node *p=NULL;
  node *q=NULL;
    while (r!=0)//r will node be pointing on r->data but no null
    {
       p=q;
       q=r;
       r=r->next;

       q->next=p;
    }
    first=q;
    
}

void concatenation(struct node *p ,struct node *q)
{
  node *ptr=p;
  while(p!=NULL)
  {
    p=p->next;
  }
  p->next=q;
  q=NULL;
  while (ptr!=NULL)
  {
    cout<<ptr->data<<" ";
    ptr=ptr->next;
  }
  
}

void merge()
{
   node *last=NULL;
   if(first->data<second->data)
   {
     third=last=first;
     first=first->next;
     last->next=NULL;
   }
   else
   {
     third=last=first;
     second=second->next;
     last->next=NULL; 
   }

   while (first!=0 && second!=0)
   {
      if(first->data<second->data)
      {
        last->next=first;
        last=first;
        first=first->next;
        last->next=NULL;
      }
      else
      {
        last->next=second;
        last=second;
        second=second->next;
        last->next=NULL; 
      }
   }
   if(first!=NULL)
   {
     last->next=first;
   }
   else
   {
     last->next=second;
   }
   
}

int main()
{
    int arr[]={10,20,30,40,50};
    create(arr,5);
    /*display(first);
    display_recusive(first);
    cout<<endl;
    rev_display_recursion(first);
    count(first);
    cout<<count_revcursive(first)<<endl;
    sum(first);
    cout<<"Sum_recur : "<<sum_recur(first)<<endl;
    cout<<"Max elements :"<<max(first)<<endl;
    cout<<"Max elements recursive :"<<max_recur(first)<<endl;
    cout<<"Elements 30 is present at : "<<linear_search_move_to_head(first,60)<<endl;
    insert(5,60);
    display(first);*/

    insert_last(70);
    insert_last(80);
    insert_last(90);
    insert_last(100);
    /*display(second);
    insert_in_a_sorted_ll(40);
    display(first);
    delete_ele(first,6);
    display(first);
    if(check_sorted(second))
    cout<<"Sorted "<<endl;
    else
    cout<<"Not sorted "<<endl;

     revmove_dubli(first);
     display(first);

     //rev(first);
     //display(first);
     concatenation(first,second);
     display(first);*/
    merge();
    display(third);
    return 0;
}