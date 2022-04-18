#include <iostream>
using namespace std;

int main()
{
    int a[3];
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    int key;
    cout << "Enter elements of the array:";
    cout << '\n';
    for (i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    cout << "Enter the element to search for:";
    cin >> key;
    int low=0;
    int high=n-1;
    int mid=0;
    int pos=-1;
    while(low<=high)
    { 
        mid=(low+(high-low))/2;

        if (a[mid] == key)
        {
            pos=mid;
            break;
        }
        else if(a[mid]>key)
          high=mid-1;
        else
           low=mid+1;
    }
    if(pos !=-1)
    cout << "Element is present at " <<pos+1<< endl;
    if(low>high)
      cout<<"Element not present in the array."<<endl;
    return 0;
}