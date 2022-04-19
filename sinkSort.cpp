// Online C++ compiler to run C++ program online
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
    int n;
    cout<<"Enter number of elements in the array:";
    cin>>n;
    int a[n];
    int len=sizeof(a)/sizeof(a[0]);
    int comparCount=0;
    cout<<"Enter elements of  the array:"<<endl;

    for (int i =0; i<n; i++)
    {
        cin >> a[i];
    }

    cout << "Elements of the  unsorted array:"<<endl;
    for (int i =0;i<n; i++)
    {
        cout<< a[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1;i>0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            if(a[j+1]<a[j])
            {
                swap(&a[j],&a[j+1]);

            }
        }
    }

    cout << "Elements of the  sorted array:"<<endl;
    for (int i =0;i<n; i++)
    {
        cout<< a[i]<<" ";
    }
    cout<<"Number of comparisons made :"<<comparCount;

    return 0;
}