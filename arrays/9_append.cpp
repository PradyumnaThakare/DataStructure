#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to be added ";
    int c;
    cin>>c;
    a[n]=c;
    cout<<"updated array "<<endl;
    for(int i=0;i<n+1;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}