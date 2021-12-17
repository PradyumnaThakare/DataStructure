#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"m,n :";
    cin>>m>>n;
    int a[5][5];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int count=0;
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(a[i][j]!=0)
           count++;
        }
    }
    cout<<"Count : "<<count;
    
    /* int m2,n2;
    cout<<"m2,n2";
    cin>>m2>>n2;
    int arr2[5][5];
    for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cin>>arr2[i][j];
        }
    }
    
    if(m==m2 && n==n2)
    {
        int ans[m][n];
        for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cout<<arr[i][j]+arr2[i][j];
        }
        cout<<endl;
    }*/
        
   // }
    return 0;
}