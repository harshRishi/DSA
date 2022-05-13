#include <iostream>
using namespace std;

void isConnected(int **edges, int v, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
            continue;

        if (edges[sv][i] == 1 && !visited[i])
        {
            isConnected(edges, v, i, visited);
        }
    }
}

int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;

    // create a v size graph matrix
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++) // initially no connection
            edges[i][j] = 0;
    }

    // now collect the edges information
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1; // connnected
        edges[b][a] = 1; // connected
    }
    /*
    if(e == v-1)
        cout << "true";
    else
        cout << "false";
    return 0;
    */
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false; // initially not visited any place
    }

    isConnected(edges, v, 0, visited);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
}