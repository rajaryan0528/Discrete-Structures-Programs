/*Create a  class SET  and  take two sets as input from user to perform following SET operations:
a.Subset : Check whether one set is a subset of other or not
b.Union and Intersection of the two sets
c.Complement : Assume Universal Set as per the input elements from the user
d. Set difference and Symmetric Difference between two SETS
e.Cartesian product of Sets
*/
#include <iostream>
using namespace std;
#include <set>
#include <utility>
class Set
{
public:
    set<int> arr;
    Set()
    {
        arr = {};
    }
    void getElements();
    void disp();
    friend set<int> Union(Set a, Set b);
    friend set<int> Intersection(Set A, Set B);
    friend void cartesianProd();
    friend set<int> setDifference(Set A, Set B); // A-B and B-A
    friend void symmDiff();                      // A-B U B-A
    friend int isSubset(Set A);
    void complement();
};

int isSubset(Set A, Set B)
{
    // if A isSubset of B
    set<int>::iterator one;
    set<int>::iterator two;
    // if B is subset  of A then n(B.A) = n(B)
    Set subset;
    subset.arr = Intersection(A, B);
    if (subset.arr.size() == A.arr.size())
        return 1;
    else
        return 0;
}

set<int> setDifference(Set A, Set B)
{
    set<int>::iterator one;
    set<int>::iterator two;
    Set C;
    C.arr = A.arr;
    for (one = A.arr.begin(); one != A.arr.end(); one++)
    {
        for (two = B.arr.begin(); two != B.arr.end(); two++)
        {
            if (*one == *two)
            {
                C.arr.erase(*one);
                break;
            }
        }
    }
    return C.arr;
}

void symmDiff(Set A, Set B)
{
    Set C;
    Set D;
    Set E;
    C.arr = setDifference(A, B);
    D.arr = setDifference(B, A);
    E.arr = Union(C, D);
    E.disp();
}

void Set::complement()
{
}

void cartesianProd(Set A, Set B)
{
    int size = A.arr.size() * B.arr.size();
    pair<int, int> eleArr[size];
    set<int>::iterator one;
    set<int>::iterator two;
    int i = 0;
    for (one = A.arr.begin(); one != A.arr.end(); one++)
    {
        for (two = B.arr.begin(); two != B.arr.end(); two++)
        {
            eleArr[i] = make_pair(*one, *two);
            i++;
        }
    }

    cout << "{  ";
    for (int i = 0; i < size; i++)
    {
        cout << eleArr[i].first << "," << eleArr[i].second << "  ";
    }
    cout << "}" << endl;
}

set<int> Union(Set A, Set B)
{
    set<int>::iterator one;
    set<int>::iterator two;
    Set uni;
    for (one = A.arr.begin(); one != A.arr.end(); one++)
    {
        uni.arr.insert(*one);
    }

    for (two = B.arr.begin(); two != B.arr.end(); two++)
    {
        uni.arr.insert(*two);
    }

    return uni.arr;
}

set<int> Intersection(Set A, Set B)
{
    set<int>::iterator one;
    set<int>::iterator two;
    Set intersection;
    for (one = A.arr.begin(); one != A.arr.end(); one++)
    {
        for (two = B.arr.begin(); two != B.arr.end(); two++)
        {
            if (*one == *two)
                intersection.arr.insert(*one);
        }
    }
    return intersection.arr;
}

void Set::getElements()
{
    cout << "Press y to exit." << endl;
    int ele = 0;
    char ans;
    bool run = true;
    do
    {
        cout << "Enter the element :";
        cin >> ele;
        arr.insert(ele);
        cout << "Do you wish to exit? y/n" << endl;
        cin >> ans;
        if (ans == 'y')
            run = false;

    } while (run != false);
}

void Set::disp()
{
    cout << "Elements of the set are :";
    cout << "{ ";
    for (set<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        cout << ' ' << *it;
    cout << " }";
    cout << endl;
}

void menu()
{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Subset - Check whether one set is a subset of other or not" << endl;
    cout << "2.Union  of the two sets" << endl;
    cout << "3.Intersection of the two sets" << endl;
    cout << "4.Complement" << endl;
    cout << "5.Set difference" << endl;
    cout << "6.Symmetric Difference" << endl;
    cout << "7.Cartesian product" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Please enter your choice:";
}
int main()
{
    Set A, B;
    Set intersection;
    Set uni;
    Set setDiff;
    int ch = -1;
    cout << "Please enter the elements of  the  first set." << endl;
    A.getElements();
    A.disp();
    cout << "--------------------------------------------------------" << endl;
    cout << "Please enter the elements of the second  set." << endl;
    B.getElements();
    B.disp();
    do
    {
        menu();
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (isSubset(A, B) == 1)
                cout << "A is subset of B" << endl;
            if (isSubset(B, A) == 1)
                cout << "B is subset of A" << endl;
            break;
        case 2:
            uni.arr = Union(A, B);
            uni.disp();
            break;
        case 3:
            intersection.arr = Intersection(A, B);
            intersection.disp();
            break;
        case 4:
            break;
        case 5:
            cout << "------------------------   A-B  --------------------" << endl;
            setDiff.arr = setDifference(A, B);
            setDiff.disp();
            cout << "-----------------------    B-A  ----------------------------" << endl;
            setDiff.arr = setDifference(B, A);
            setDiff.disp();
            break;
        case 6:
            symmDiff(A, B);
            break;
        case 7:
            cartesianProd(A, B);
            break;

        default:
            if (ch == 0)
                cout << "Task Exited." << endl;
            else
                cout << "Please enter a valid choice." << endl;
        }

    } while (ch != 0);
    return 0;
}