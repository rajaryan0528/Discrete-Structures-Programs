/*Given a full m-ary tree with i internal vertices. WAP to find the number of leaf nodes*/

#include <iostream>
using namespace std;

int numOfLeafNodes(int m, int v)
{
    int i = (v - 1) / m;
    int l = (m - 1) * i + 1;
    return l;
}

int main()
{
    int m, v;
    cout << " m is the maximum number of child nodes a parent node can have."<<endl;
    cout<< "Enter  the value of m: ";
    cin >> m;
    cout << "Enter the number of vertices of the tree: ";
    cin >> v;
    cout << "Number of leaves: " << numOfLeafNodes(m, v);
    return 0;
}