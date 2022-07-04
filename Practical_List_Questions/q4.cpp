/*Use the function defined in Q3 to check whether the given relation is :
 a.Eqivalent
 b.Partial Order Relation or
 c.None
 */

#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <String>
#include "relationHeader.h" // "" signify it is a local header file

bool isEquivalent(int *arr, int s)
{
    if (isTransitive(arr, s) == 1 && isReflexive(arr, s) == 1 && isSymmetric(arr, s) == 1)
        return true;
    else
        return false;
}

bool isPartialOrderRelation(int *arr, int s)
{
    if (isTransitive(arr, s) == 1 && isReflexive(arr, s) == 1 && isAntiSymmetric(arr, s) == 1)
        return true;
    else
        return false;
}

int main()
{
    int s, e;
    vector<int> set;

    cout << "Enter the cardinality of the set: ";
    cin >> s;

    int arr[s][s];
    for (int i = 0; i < s; i++) // initializing the whole matrix to 0
    {
        for (int j = 0; j < s; j++)
        {
            arr[i][j] = 0;
        }
    }

    cout << "Enter the  set on which the relation is defined :" << endl;
    for (int i = 0; i < s; i++)
    {
        cin >> e;
        set.push_back(e);
    }

    int n;
    cout << "Enter the number of pairs in the relation :";
    cin >> n;
    pair<int, int> rSet[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements of the relation (pairwise) :" << endl;
        cin >> rSet[i].first;
        cin >> rSet[i].second;
    }

    int a, b;
    for (int i = 0; i < n; i++)
    {
        a = rSet[i].first;
        b = rSet[i].second;
        arr[a][b] = 1;
    }

    cout << "Matrix Representation of the above relation :" << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    string ans1, ans2;
    ans1= isEquivalent((int *)arr, s) ? "Relation is Eqivalent" : "Relation is not Equivalent";
    cout << ans1 << endl;
    ans2 = isPartialOrderRelation((int *)arr, s) ? "Relation is Partial Order Relation" : "Relation is not a  Partial Order Relation";
    cout << ans2 << endl;
    if (ans1 == "Relation is not Equivalent" and ans2 == "Relation is not a  Partial Order Relation")
        cout << "Relation is neither Equivalent nor Partial Order Relation. " << endl;
    return 0;
}