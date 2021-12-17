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
  int i=0,j=n1-1;
 while(i<=j)
 {
     int t=arr1[j];
     arr1[j]=arr1[i];
     arr1[i]=t;
     i++;
     j--;
 }
 cout<<"Rev arr : ";
  for(int b=0;b<n1;b++)
  {
      cout<<arr1[b]<<" ";
  }

}