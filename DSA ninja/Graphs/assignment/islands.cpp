#include <iostream>
using namespace std;

void islands(int **edges, int v, int sv, bool *visited)
{
    // mark the sv visited
    visited[sv] = true;
    // check ajacent
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
            continue;

        if (edges[sv][i] == 1 && !visited[i])
        {
            islands(edges, v, i, visited);
        }
    }
    return;
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

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false; // initially not visited any place
    }

    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            islands(edges, v, i, visited);
            count++;
        }
    }
    cout << count;
}