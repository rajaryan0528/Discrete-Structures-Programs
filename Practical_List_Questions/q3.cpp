/*Create a class RELATION, use matrix notation to represent a relation.Include functions to check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. WAP to use this class.*/

#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <string>

bool isTransitive(int *arr, int s)
{
    bool yes = true;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < s; k++)

                if ((*(arr + i * s + j) == 1) && (*(arr + j * s + k) == 1) && (*(arr + i * s + k) != 1))
                    yes = false;
        }
    }
    return yes;
}

bool isReflexive(int *arr, int s)
{
    bool yes = true;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if ((*(arr + i * s + i) == 1))
                yes = true;
        }
    }

    return yes;
}

bool isSymmetric(int *arr, int s)
{
    bool yes = true;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if ((*(arr + i * s + j) == 1) & (*(arr + j * s + i) != 1))
                yes = false;
        }
    }

    return yes;
}

bool isAntiSymmetric(int *arr, int s)
{
    bool yes = true;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if ((*(arr + i * s + j) == 1) & (*(arr + j * s + i) != 1))
                yes = true;
            else if (i == j)
                yes = true;
            else
                yes = false;
        }
    }

    return yes;
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

    string ans;
    ans = isSymmetric((int *)arr, s)?"Relation is Symmetric":"Relation is not Symmetric";
    cout << ans << endl;
    ans = isAntiSymmetric((int *)arr, s)?"Relation is AntiSymmetric":"Relation is not AntiSymmetric";
    cout << ans << endl;
    ans = isReflexive((int *)arr, s)?"Relation is Reflexive":"Relation is not Reflexive";
    cout << ans << endl;
    ans = isTransitive((int *)arr, s)?"Relation is Transitive":"Relation is not Transitive";
    cout << ans << endl;
    return 0;
}