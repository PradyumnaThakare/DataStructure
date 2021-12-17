#include<iostream>
using namespace std;

int linear(int key,int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==key)
        return i;
    }
    return -1;
}
int linear_transpostion(int key,int arr[],int len)
{
    int temp;
    for(int i=0;i<len;i++)
    {
        if(arr[i]==key)
        {
            temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
            return i-1;
        }
    }
    return -1;
}
int linear_moveTOhead(int key,int arr[],int len)
{
    int temp;
    for(int i=0;i<len;i++)
    {
        if(arr[i]==key)
        {
            temp=arr[i];
            arr[i]=arr[0];
            arr[0]=temp;
            return 0;
        }
    }
    return -1;
}

int binary(int key,int arr[],int len)
{
    int start=0,end=len-1,mid=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        start=mid+1;
        else
        end=mid-1;
    }
    return -1;
}
int main()
{
    int len;
    cin>>len;
    int *arr=new int[100];
    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    cout<<"Key : ";
    int key;
    cin>>key;
    cout<<linear(key,arr,len)<<endl;
    cout<<linear_transpostion(key,arr,len)<<endl;
    cout<<linear_moveTOhead(key,arr,len)<<endl;
    cout<<binary(key,arr,len)<<endl;
    return 0;
}
