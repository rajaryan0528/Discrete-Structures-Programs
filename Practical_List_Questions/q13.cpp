/*WAP to accept the truth values of variables x and y, and print the truth table of the following logical operations: :
 a.Conjuction -AND
 b.Disjunction -OR
 c.Exclusive OR
 d.Conditional
 e.Bi-Conditional
 f.Exclusive NOR
 g.Negation
 h.NAND
 i.NOR
 */

#include <iostream>
using namespace std;
#include <vector>

class Connectives
{

public:
    int n = 4;
    vector<int> x;
    vector<int> y;
    vector<int> res;
    vector<int> get();
    vector<int> disp();
    vector<int> conjunction();
    vector<int> disjunction();
    vector<int> negation();
    vector<int> nAND();
    vector<int> nOR();
    vector<int> xOR();
    vector<int> xNOR();
    vector<int> conditional();
    vector<int> biConditional();
};

vector<int> Connectives::biConditional()
{

    // x<-->y <=> (x'+y).(y'+x)
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back((!x[i] + y[i]) * (!y[i] + x[i]));
    }

    return res;
}

vector<int> Connectives::conditional()
{

    // x-->y <=> x'+y
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(!x[i] || y[i]);
    }
    return res;
}

vector<int> Connectives::xOR()
{
    // odd 1's counter , this valid for 2 input xOR gate
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == y[i])
            res.push_back(0);
        else
            res.push_back(1);
    }
    return res;
}

vector<int> Connectives::xNOR()
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == y[i])
            res.push_back(1);
        else
            res.push_back(0);
    }
    return res;
}

vector<int> Connectives::get()
{
    int a = 0;
    cout << "Enter values of x:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        x.push_back(a);
    }
    a = 0;
    cout << "Enter values of y:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        y.push_back(a);
    }
    return res;
}

vector<int> Connectives::disp()
{
    cout << "x"
         << "\t"
         << "y" << endl;
    for (int i = 0; i < 4; i++)
        cout << x[i] << "\t" << y[i] << endl;
    return res;
}

vector<int> Connectives::conjunction()
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(x[i] * y[i]);
    }
    return res;
}

vector<int> Connectives::nAND()
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(!(x[i] * y[i]));
    }
    return res;
}

vector<int> Connectives::nOR()
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(!(x[i] || y[i]));
    }

    return res;
}

vector<int> Connectives::disjunction()
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(x[i] || y[i]);
    }
    return res;
}

vector<int> Connectives::negation()

{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(!x[i]);
    }

    // first four elements will contain the negation of the values of x and the next four values that of  y
    for (int i = 0; i < n; i++)
    {
        res.push_back(!y[i]);
    }
    return res;
}

void menu()
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "Please select an operation from the list below:" << endl;
    cout << "1.Conjuction - AND" << endl;
    cout << "2.Disjunction - OR " << endl;
    cout << "3.Exclusive OR " << endl;
    cout << "4.Conditional " << endl;
    cout << "5.Bi - Conditional " << endl;
    cout << "6.Exclusive NOR" << endl;
    cout << "7.Negation " << endl;
    cout << "8.NAND " << endl;
    cout << "9.NOR" << endl;
    cout << "0.Exit" << endl;
    cout << "-------------------------------------------------------------------" << endl;
}
int main()
{
    Connectives obj;
    obj.get();
    obj.disp();
    bool run = true;
    int ch;
    do
    {
        menu();
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x AND y" << endl;
            obj.res = obj.conjunction();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;
        case 2:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x OR y" << endl;
            obj.res = obj.disjunction();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;
        case 3:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x XOR y" << endl;
            obj.res = obj.xOR();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;

        case 4:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x --> y" << endl;
            obj.res = obj.conditional();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;

        case 5:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x <=> y" << endl;
            obj.res = obj.biConditional();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;

        case 6:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x XNOR y" << endl;
            obj.res = obj.xNOR();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;

        case 7:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << " !x "
                 << "\t"
                 << " !y" << endl;
            obj.res = obj.negation();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << "\t" << obj.res[i + 4] << endl;
            break;

        case 8:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x NAND y" << endl;
            obj.res = obj.nAND();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;
        case 9:
            cout << "x"
                 << "\t"
                 << "y"
                 << "\t"
                 << "x NOR y" << endl;
            obj.res = obj.nOR();
            for (int i = 0; i < 4; i++)
                cout << obj.x[i] << "\t" << obj.y[i] << "\t" << obj.res[i] << endl;
            break;
        default:
            if (ch == 0)
            {
                run = false;
                cout << "Task ended." << endl;
            }
            else
                cout << "Enter a valid choice !!";
            break;
        }
    } while (run != false);

    return 0;
}