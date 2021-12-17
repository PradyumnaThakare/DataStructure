#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[10];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int x;
  
  cout<<"Enter the index u want to delete : "<<endl;
  cin>>x;
  while(x<n)
  {
    arr[x]=arr[x+1];
    x++;
  }
  n=n-1;
  cout<<"Arr : ";
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}