#include <iostream>
using namespace std;

void power(int *adjMatrix, int *I, int *res, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum=0;
            for (int k = 0; k < n; k++)

            {

               sum += (*(adjMatrix + i * n + k)) * (*(I + k * n + j));
            }
            *(res + i * n + j)=sum;
        }
    }

    // Updating identity matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            *(I + i * n + j) = *(res + i * n + j);
        }
    }
}

void multiply(int *adjMatrix, int *I, int *res, int n, int k)
{
    for (int i = 1; i <= k; i++)
    {
        power((int *)adjMatrix, (int *)I, (int *)res, n);
    }
}

int main()
{
    int e, n;
    cout << "Enter number of vertices:";
    cin >> n;
    int adjMatrix[n][n]={{1,0,1,0,0},{0,1,0,0,0,1},{0,0,1,0,0},{0,0,0,1,0},{1,0,0,0,1}};
    int I[n][n];
    int res[n][n];
    for (int i = 0; i < n; i++) // Identity Matrix
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
        }
        cout << endl;
    }

    cout << "Enter total number of edges:";
    cin >> e;
    

    cout << "Adjacency matrix for the data provided:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << "  ";
        }
        cout << endl;
    }

    int k=0;
    cout << "Enter the length of the path:";
    cin >> k;
    multiply((int *)adjMatrix, (int *)I, (int *)res, n, k);

    cout << "Adjacency matrix raised to the power" << k << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
