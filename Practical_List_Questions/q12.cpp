/*For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 + ... + xn = C, where C is a constant(C <= 10) and x1, x2, x3, ..., xn are non-negative integers using brute force strategy.*/

#include <iostream>
using namespace std;

void print_array(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void find_solutions(int x[], int m, int n, int c)
{
    // Sum of x[m], ..., x[n-1] should be equal k
    if (m == n)
    {
        return;
    }

    if (c == 0)
    {
        print_array(x, n);
        return;
    }

    for (int i = 0; i < c; i++)
    {
        x[m] = i;
        find_solutions(x, m + 1, n, c- i);
    }
    x[m] = c;
    print_array(x, n);
    x[m] = 0;
}

int main()
{
    int x[10] = {0};
    cout<<"Enter the value for n :";
    int n;
    cin >> n;
    if (n > 10)
    {
        cout << "n is too big" << endl;
        exit(1);
    }

    int c;
    cout<<"Enter the value for c :";
    cin >> c;

    cout << endl;
    find_solutions(x, 0, n, c);
    return 0;
}
