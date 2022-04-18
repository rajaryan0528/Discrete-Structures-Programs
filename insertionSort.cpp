#include <iostream>
using namespace std;1

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
    cout << "Elements of the  unsorted array:" << endl;
    for (i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    cout << endl;
    int current=0,j=0;
    for (i = 0; i < n - 1; i++)
    {
        current=a[i];
        j=i-1;
        while(j>=0 && a[j]>current)
        {
            a[j+1]=a[j];
            j=j-1;

        }
        a[j+1]=current;
    }
    cout << "Elements of the  sorted array:" << endl;
    for (i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    return 0;
}