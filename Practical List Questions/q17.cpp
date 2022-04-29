// WAP to accept a directed graph G and compute the in-degree and out-degree of each vertex.
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

int checkMatrix(int *adjMatrix, int n, int i, int j)
{
    if (*(adjMatrix + j * n + i) == 1)
        return 1;
    if (*(adjMatrix + j * n + i) == 0)
        return 0;
    if (*(adjMatrix + j * n + i) == -1)
        return -1;
}

int main()
{
    int n;
    cout << "Enter total number of vertices in the graph:";
    cin >> n;
    int adjMatrix[n][n];
    int vertexList[n];
    for (int i = 0; i < n; i++)
    {
        vertexList[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    int e;
    cout << "Enter total number of edges in the graph:";
    cin >> e;
    Edge edgeList[e];
    int v = 0, u = 0;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter edge:" << endl;
        cin >> v >> u;
        edgeList[i].addEdge(v, u);
    }
    cout<<"You entered the following edges:"<<endl;
    for (int i = 0; i < e; i++)
    {
        edgeList[i].dispEdge();
    }
    cout<<endl;

    // Populating the adjacency matrix for the graph entered
    // n- number of vertices e- number of edges
    int i = 0, j = 0;
    for (int k = 0; k < e; k++)
    {
        i = edgeList[k].startingVertex;
        j = edgeList[k].endingVertex;
        if (checkMatrix((int *)adjMatrix, n, i, j) == 0)
            adjMatrix[i][j] = 1;

        if (checkMatrix((int *)adjMatrix, n, i, j) == 1)
            adjMatrix[i][j] = -1;
    }
   
   //displaying the adjacency matrix of the given graph 
   cout<<"Adjacency Matrix for the provided digraph"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout <<" "<<adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    //calulating the in degree and out degree of each vertex in the graph using the adjacency matrix generated
    for (int i = 0; i < n; i++)
    {
        int outdeg=0;
        int indeg=0;
        for (int j = 0; j < n; j++)
        {
            if(adjMatrix[i][j]==1)
                outdeg++;
            if(adjMatrix[i][j]==-1)
                 indeg++;
        }
        cout <<vertexList[i]<<"\t"<<"Indegree:"<<indeg<<" |"
             <<"Outdegree:"<<outdeg<<endl;
    }
    return 0;
}