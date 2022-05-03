// Given a graph G, write a program to find the number of paths of length k between the source and the destination entered by the user.

// PROP. (A^n)_{ij} holds the number of paths of length n from node i to node j.
//Link for the description of the method
// https://quickmathintuitions.org/finding-paths-length-n-graph/
#include <iostream>
using namespace std;

class Edge
{

public:
    int startingVertex;
    int endingVertex;
    void addEdge(int v, int u)
    {
        startingVertex = v;
        endingVertex = u;
    }

    void dispEdge()
    {
        cout << "(" << startingVertex << "," << endingVertex << ")"
             << "  ";
    }
};

// this block of code multipies the adjMatrix k number of times -->adjMatrix^k
void power(int *adjMatrix, int *I, int *res, int n)
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                *(res + i * n + j) += (*(adjMatrix + i * n + k)) * (*(I + k * n + j));
            }
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
    for (int i = 1; i <= k; ++i)
    {
        power((int *)adjMatrix, (int *)I, (int *)res, n);
    }
}

int main()
{
    int e, n;
    cout << "Enter number of vertices:";
    cin >> n;
    int adjMatrix[n][n];
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

    for (int i = 0; i < n; i++) // initializing the whole matrix to 0
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
            res[i][j] = 0;
        }
        cout << endl;
    }

    cout << "Enter total number of edges:";
    cin >> e;
    Edge edgeList[e];
    int v = 0, u = 0;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter edge:" << endl;
        cin >> v >> u;
        edgeList[i].addEdge(v, u);
    }

    /*
    cout << "You entered the following edges:" << endl;
    for (int i = 0; i < e; i++)
    {
        edgeList[i].dispEdge();
    }
    cout << endl;
    */

    // populating the adjacency  matrix for the data entered
    int i = 0, j = 0;
    for (int k = 0; k < e; k++)
    {
        i = edgeList[k].startingVertex;
        j = edgeList[k].endingVertex;
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }

    cout << "Adjacency matrix for the data provided:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    
    //finding the path of length k from src to dest.
    int src = 0, dest = 0, k = 0;
    cout << "Enter the source:";
    cin >> src;
    cout << "Enter the destination:";
    cin >> dest;
    cout << "Enter the length of the path:";
    cin >> k;
    multiply((int *)adjMatrix, (int *)I, (int *)res, n, k);
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout << "Adjacency matrix raised to the power " << k << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "Number of paths of length " << k << " between the nodes " << src << " and " << dest << " are: " << res[src][dest] << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    return 0;
}
