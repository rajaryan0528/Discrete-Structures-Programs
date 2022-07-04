/*WAP to implement Bubble Sort. Find the number of comparisons during each pass and display the intermediate result.Use the observed values to plot a graph to analyze the complexity of algorithm*/
#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void disp(vector<int> &v )
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void write(int comparCount, int n)
{
    ofstream myFile;                                  // file pointer
    myFile.open("sortBubbleData.csv", ios_base::app); // appending to the file
    myFile << comparCount << "," << n << "\n";        // newline is the delimiter
    myFile.close();
}

int main() 
{
    int n;
    vector<int> arr(n,0);
    int comparCount=0;
    cout<<"Enter the number of  elements in   the array:"<<endl;
    cin>>n;
    int e;
    cout<<"-----------Entering array elements------------"<<endl;
    for (int i =0; i<n; i++)
    {
        cin>>e;
        arr.push_back(e);
    }

    cout << "Elements of the unsorted array:"<<endl;
    for (int i =0;i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"--------------------------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                comparCount+=1;
                cout<<"Swap : ";
                disp(arr);

            }
        }
        cout << "Array after pass number " << i << "-------------" << endl;
        disp(arr);
    }

    cout << "Elements of the  sorted array:"<<endl;
    for (int i =0;i<n; i++)
    {
        cout<< arr[i]<<" ";
    }
    // array of length n in worst case (n-1)(n-2).......1 = n(n-1)/2 comparisons
    cout<<endl;
    cout<<"Number of comparisons made :"<<comparCount;
    write(comparCount,n);
    return 0;
}