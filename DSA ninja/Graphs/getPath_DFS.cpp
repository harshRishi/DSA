#include <iostream>
#include <vector>
using namespace std;

vector<int> getPath_DFS(int **edges, int v, int source, int destination, bool *visited)
{
    // make an output array vector
    vector<int> path;
    // check if source and destination are same
    if (source == destination)
    {
        path.push_back(source);
        return path;
    }
    // make the path visited
    visited[source] = true;

    // search the edges
    for (int i = 0; i < v; i++)
    {
        // check if i and source is same if yes continue
        if (i == source)
            continue;

        // search adjacent of source && not visited
        if (edges[source][i] == 1 && !visited[i])
        {
            visited[i] = true;
            path = getPath_DFS(edges, v, i, destination, visited);

            if (path.size() != 0)
            {
                path.push_back(source);
                return path;
            }
            // if (getPath_DFS(edges, v, i, destination, visited) != NULL)
            // {
            //     path.push_back(source); // in Case getpath get us some NULL than don't add that to out path
            //     return path;
            // }
        }
    }
    return path; // in Case we didn't found the path
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

    vector<int> result = getPath_DFS(edges, v, source, destination, visited);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    delete[] visited;
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}