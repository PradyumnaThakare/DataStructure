#include<iostream>
using namespace std;
int main()
{
  cout<<"Enter the size of the array1 : ";
  int n1;
  cin>>n1;
  int arr1[10];
  cout<<"Enter the elements of the array1 : "<<endl;
  for(int i=0;i<n1;i++)
  {
    cin>>arr1[i];
  }
  cout<<"Enter the size of the array2 : ";
  int n2;
  cin>>n2;
  int arr2[10];
  cout<<"Enter the elements of the array2 : "<<endl;
  for(int i=0;i<n2;i++)
  {
    cin>>arr2[i];
  }
  int arr3[20];
  int final_size=n1+n2;
  
  int x=0,z=0,i=0;
  while(z<n1 && x<n2)
  {
      if(arr1[z]<=arr2[x])
      {
          arr3[i]=arr1[z];
          i++;
          z++;
      }
      else
      {
          arr3[i]=arr2[x];
          i++;
          x++;
      }
  }
  for(;z<n1;z++)
  {
      arr3[i]=arr1[z];
      i++;
     
  }
  for(;x<n2;x++)
  {
      arr3[i]=arr2[z];
      i++;
    
  }
  cout<<"Merged array : ";
  for(int i=0;i<final_size;i++)
  {
    cout<<arr3[i]<<" ";
  }
}