#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
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
    cout << "Elements of the  unsorted array:" << endl;
    for (i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    cout << endl;
    int minInd = 0;
    for (i = 0; i < n - 1; i++)
    {
        minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[minInd])
                minInd = j;
            swap(&a[minInd], &a[j]);
        }
    }
    cout << "Elements of the  sorted array:" << endl;
    for (i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    return 0;
}