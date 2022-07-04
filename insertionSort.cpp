/*WAP to implement Insertion Sort. Find the number of comparisons during each pass and display the intermediate result.Use the observed values to plot a graph to analyze the complexity of algorithm*/
#include <iostream>
using namespace std;
#include <vector>

void disp(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    vector<int> arr(n,0);
    cout << "Enter elements of the array:"<<endl;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    cout << "Elements of the  unsorted array:" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout<<endl<<"--------------------------------------------"<<endl;
    cout << endl;
    int current=0,j=0;
    for (int i = 0; i < n - 1; i++)
    {
        current=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>current)
        {
            arr[j+1]=arr[j];
            j=j-1;

        }
        arr[j+1]=current;
    }
    cout << "Elements of the  sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    return 0;
}