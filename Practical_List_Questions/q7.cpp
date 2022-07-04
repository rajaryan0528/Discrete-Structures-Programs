// WAP to generate binary search using recursion
#include <iostream>
using namespace std;
int binarySearch(int arr[], int low, int high, int x)
{
    if(high>=low)
    {

     int mid = (low + high) / 2;
     if (arr[mid] == x){
        return mid;
    }

    if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);

    return binarySearch(arr, mid + 1, high, x);

    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the length of the array :";
    cin >> n;
    int arr[n];
    cout << "Enter the array :"<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout<<"Enter the element to be searched :";
    cin>>key;
  
    int result = binarySearch(arr,0,n-1,key);
    if(result==-1)
      cout<<"Element is not present"<<endl;
    else
       cout<<"Element present at index :"<<result;
    return 0;
}