#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of row  : ";
    int r;
    cin>>r;
    cout<<"Enter the size of colune  : ";
    int c;
    cin>>c;
    int arr[5][5];
    cout<<"input the element in 2d Arr : "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"Enter the value of arr["<<i<<"]"<<" ["<<j<<"] : ";
            cin>>arr[i][j];
            cout<<endl;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}