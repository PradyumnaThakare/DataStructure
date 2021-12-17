#include<iostream>
using namespace std;
int main()
{
  int **a;
  a=new int*[3];//row (3)
  for(int i=0;i<3;i++)
  {
    a[i]=new int[4];//col(4)
    for(int j=0;j<4;j++)
    {
      cin>>a[i][j];
    }
  }

  for(int i=0;i<3;i++)
  {
    delete []a[i];
  }
  delete []a;
  return 0;
}