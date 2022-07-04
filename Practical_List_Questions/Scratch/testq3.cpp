/*Create a class RELATION, use matrix notation to represent a relation.Include functions to check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. WAP to use this class.*/

#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#define MAX_LEN 50
class relation
{
public:
    int setSize = 0;

    vector<int> set;                       // set in which the relation is defined
    int *arr = new int[setSize * setSize]; // matrix representation of the relation
    pair<int, int> rSet[MAX_LEN];          // pairs of images and their preimages
    int n;
    vector<int>row(setSize,0);
    vector<vector<int>> rArr(setSize, row);
    relation()
    {
        int e;
        cout << "Enter the cardinality of the set: ";
        cin >> setSize;
        cout << "Enter the  set on which the relation is defined :" << endl;
        for (int i = 0; i < setSize; i++)
        {
            cin >> e;
            set.push_back(e);
        }
    }
    void getElements();
    void fillMatrix();
    void isReflexive();
    void isSymmetric();
    void isAntiSymmetric();
    void isTransitive();
    void disp()
    {
        for (int i = 0; i < setSize; i++)
        {
            for (int j = 0; j < setSize; j++)
            {
                cout << *(arr + i * setSize + j) << " ";
            }
            cout << endl;
        }
    }
};

void relation::isAntiSymmetric()
{
    bool yes = true;
    for (int i = 0; i < setSize; i++)
    {
        for (int j = 0; j < setSize; j++)
        {
            if ((i!=j) & (*(arr + i * setSize + j) == 1) & (*(arr + j * setSize + i) == 1))
                yes = false;
        }
    }

    cout << yes << endl;
}

void relation::isSymmetric()
{
    bool yes = true;
    for (int i = 0; i < setSize; i++)
    {
        for (int j = 0; j < setSize; j++)
        {
            if ((*(arr + i * setSize + j) == 1) & (*(arr + j * setSize + i) !=1))
                yes = false;
        }
    }

    cout<<yes<<endl;
}

void relation::isReflexive()
{
    bool yes = true;
    for (int i = 0; i < setSize; i++)
    {
        for (int j = 0; j < setSize; j++)
        {
            if ( (*(arr + i * setSize + i) == 1))
                yes = true;
        
        }
    }

    cout << yes << endl;
}

void relation::fillMatrix()
{

    for (int i = 0; i < setSize; i++)
    {
        for (int j = 0; j < setSize; j++)
        {
            *(arr + i * setSize + j) = 0;
        }
    }


    int a = 0;
    int b = 0;
    

    for (int i = 0; i < 5; i++)
    {
        a = rSet[i].first;
        b = rSet[i].second;
        *(arr + a * setSize + b) = 1;
    }
}

void relation::getElements()
{
    char ans;
    for (int i = 0;; i++)
    {
        cout << "Enter the elements of the relation (pairwise) :" << endl;
        cin >> rSet[i].first;
        cin >> rSet[i].second;
        cout << "Do you wish to exit (y/n) :";
        cin >> ans;
        if (ans == 'y')
            break;
    }
    fillMatrix();
}

int main()
{
    relation r1;
    r1.getElements();
    r1.disp();
    r1.isReflexive();
    r1.isSymmetric();
    r1.isAntiSymmetric();

    return 0;
}
