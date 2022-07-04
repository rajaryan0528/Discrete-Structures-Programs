#include <iostream>
using namespace std;
#include <vector>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    cout << "Enter elements of the array:";
    cout << '\n';
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    cout << "Elements of the  unsorted array:" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
    int minInd = 0;
    for (int i = 0; i < n - 1; i++)
    {
        minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInd])
                minInd = j;
            swap(&arr[minInd], &arr[j]);
        }
    }
    cout << "Elements of the  sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    return 0;
}