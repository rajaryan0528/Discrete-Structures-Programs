#include <iostream>
using namespace std;

int main()
{
    int a[4];
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    int key;
    cout << "Enter elements of the array:";
    cout << '\n';
    for (i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    cout<<"Enter the element to search for:";
    cin>>key;
    bool found=false;
    for (i = 0; i < n; i++)
    {

      if(a[i]==key)
      {
          cout<<"Element found at position "<<i+1<<endl;
          found=true;
          break;
      }

    }
if(found==false)
    cout<<"Element is not present in the array."<<endl;
return 0;
}