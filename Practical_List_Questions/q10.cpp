/*WAP that generates all the permutations of a given set of digits, with or without repetition.(For example , if the given set is {1,2}, the permutations are 12 and 21).*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void disp(int set[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<set[i]<<",";
    }
    cout<<endl;
}


void permutation(int set[],int n )
{
    vector<int>:: iterator it;

    do
    {
        disp(set,n);

    } while (next_permutation(set, set+n)); // arranges the array in the next lexographical order return a bool value
}



int main()
{
   
    vector<vector<int>> permutations;
    int n;
    cout << "Number of elements in the set :";
    cin >> n;
    int set[n];
    cout << "---------------- Set Elements ---------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    permutation(set, n);
    return 0;
}
