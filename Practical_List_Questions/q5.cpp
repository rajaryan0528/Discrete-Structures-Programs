//WAP to generate fibonacci series using recursion
// Fn= Fn-1 + Fn-2   given f0=0 and f1=1
#include <iostream>
using namespace std;

int fib(int n)
{
    //seed values
    if(n==0)
       return 0;
     else if(n==1)
       return 1;
    else
     return fib(n-1)+fib(n-2);

}

int main()
{
    int n;
    cout<<"Enter the number of terms to be displayed :";
    cin>>n;
    for(int i=0;i<n;i++)
      cout<<fib(i)<<" ";
    return 0;
}
