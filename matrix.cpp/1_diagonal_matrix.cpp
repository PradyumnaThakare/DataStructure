#include<iostream>
using namespace std;
class diagonal
{
  private:
  int *arr;
  int n;
  public:
  diagonal(int n)
  {
    this->n=n;
    arr=new int[n];
  }
  void set(int i,int j,int key);
  int get(int i,int j);
  void display();
 ~ diagonal(){
      delete []arr;
  }
};
void diagonal::set(int i,int j,int key)
{
    if(i==j)
    arr[i]=key;
}
int diagonal:: get(int i,int j)
{
   if(i==j)
   return arr[i];
   else
   return 0;
}
void diagonal::display()
{
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
}
int main()
{
  diagonal d(5);
  d.set(0,0,1);
  d.set(1,1,1);
  d.set(2,2,1);
  d.set(3,3,1);
  d.set(4,4,1);
  d.display();
  return 0;
}