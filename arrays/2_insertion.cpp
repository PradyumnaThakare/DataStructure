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
  
  cout<<"Enter the index where u want to add the element : "<<endl;
  cin>>x;
  
  int last_element=n+1;
  while(x<last_element)
  {
    int t=arr[last_element];
    arr[last_element]=arr[last_element-1];
    arr[last_element-1]-t;
    last_element--;
  }
  cout<<"Which element : ";
  int key;
  cin>>key;
  arr[x]=key;
  cout<<"Arr : ";
  for(int i=0;i<n+1;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}