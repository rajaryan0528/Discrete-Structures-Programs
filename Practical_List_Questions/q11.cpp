/*Write a Program to calculate Permutation and Combination for an input value n and r using
recursive formula of  nCr and nPr */

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n)
        return (n * factorial(n - 1));
    else
        return 1;
}

void combNPerm(int n, int r)
{
    // 0<=r<=n
    if (n > 0 && r >= 0 && r <= n)
    {
        cout << endl
             << n << "C" << r << " = " << factorial(n) / (factorial(r) * factorial(n - r))
             <<endl;

        cout << endl
             << n<<"P"<<r<<" = " << factorial(n) / factorial(n - r) << endl
             <<endl;
    }

    else
        cout << "Note : 0<=r<=n" << endl;
}


   

int main()
{
    int n;
    int r;

    cout << "Enter the value for n :";
    cin >> n;
    cout << "Enter the value for r :";
    cin >> r;
    combNPerm(n , r);
}
