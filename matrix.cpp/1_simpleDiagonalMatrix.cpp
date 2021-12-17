#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"m,n :";
    cin>>m>>n;
    int arr[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          if(i==j)
          cout<<arr[i]<<" ";
          else
          cout<<"0"<<" ";
      }
      cout<<endl;
  }
    return 0;
}