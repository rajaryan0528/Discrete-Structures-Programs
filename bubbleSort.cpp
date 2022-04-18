#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}

int main()
{
    int a[4];
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    cout << "Enter elements of the array:";
    cout << '\n';
    for (i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    cout << "Elements of the  unsorted array:"<<endl;
    for (i = 0; i < n; i++)
    {

        cout<< a[i]<<" ";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {

     for(int j=0;j<n-1;j++)
     {
        if(a[i]<a[j])
         swap(&a[i],&a[j]);
     }
    }
    cout << "Elements of the  sorted array:" << endl;
    for (i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    return 0;
}