// just a sillly mistake all though I tough TA lol
#include <iostream>
using namespace std;

bool hasPath_DFS(int **edges, int v, int source, int destination, bool *visited)
{
    if (source == destination)
    {
        return true;
    }
    visited[source] = true;
    // check if initial source's adjacent have an edge with destination
    for (int i = 0; i < v; i++)
    {
        if (i == source) // no sence to check if i and souce have same value
            continue;

        // check source's adjacent && alse before calling recusion check visited
        if (edges[source][i] == 1 && !visited[i])
        {
            if (hasPath_DFS(edges, v, i, destination, visited)) // dont return untill we get true if we dont get true this function will return false at line 25
                return true;
        }
    }
    return false;
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

    // take source and distination
    int source, destination;
    cin >> source >> destination;

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false; // initially not visited any place
    }

    bool result = hasPath_DFS(edges, v, source, destination, visited);
    delete[] visited;
    if (result)
        cout << "true";
    else
        cout << "false";

    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
