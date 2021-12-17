#include<iostream>
using namespace std;
int main()
{
  int i=0;
  int *p=new int[5];
  for(int i=0;i<5;i++)
  {
    cin>>p[i];
  }
  cout<<"Enter how many more elements u want ro enter : ";
  int n;
  cin>>n;
  int *q=new int[5+n];
  
  for(int i=0;i<5;i++)
  {
     q[i]=p[i];
  }
  delete[]p;
  p=q;
  q=NULL;
  for(int i=5;i<n+5;i++)
  {
    cin>>p[i];
  }
  for(int i=0;i<n+5;i++)
  {
    cout<<p[i]<<" ";
  }
  delete[]p;
  return 0;
}