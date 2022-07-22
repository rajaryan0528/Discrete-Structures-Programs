/*Write  a  Program  to  store  a  function  (polynomial/exponential),  and  then  evaluate  the
polynomial.For example store f(x) = 4n^3 + 2n + 9 in an array and for a given value
of n, say n = 5, evaluate (i.e. compute the value of f(5).*/

/* For example, the polynomial x^100+2x^2+1 would be represented by this list: [[100, 1], [2, 2], [0, 1]]*/

#include <iostream>
using namespace std;
#include <cmath>

class monomial
{

public:
    int coefficient;
    int power;
    void addTerm(int c, int po)
    {
        coefficient = c;
        power = po;
    }

    void dispTerm()
    {
        cout << coefficient << "x^" << power << "+";
    }

    int calcvalue(int r)
    {
        
        return coefficient * pow(r, power);
    }

};


int main()
{
    int n;
    cout << "Enter the number of terms in the polynomial :";
    cin >> n;
    monomial p[n];
    int c, po;
    for (int i = 0; i < n; i++)
    {
        cout << "Coefficient:";
        cin >> c;
        cout << "Exponent:";
        cin >> po;
        p[i].addTerm(c, po);
    }

   
    
    int root;
    cout<<"Enter root :";
    cin>>root;

    int val=0;
    for(int i=0;i<n;i++)
    {
     
      val+=p[i].calcvalue(root);
    }
    
    cout<<"----------------------------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        p[i].dispTerm();
    }

    cout << "\n----------------------------------" << endl;
    cout<<"The above polynomial function solved for n= "<<root<<" results in : "<<" "<<val;
    return 0;
}
