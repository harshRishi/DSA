#include <bits/stdc++.h>
using namespace std;
bool hasPath(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    if (edges[v1][v2] == 1)
    {
        return true;
    }

    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    // bool ans = false;
    while (q.size() != 0)
    {
        int current = q.front();
        q.pop();
        if (current == v2)
        {

            return true;
        }
        for (int i = 0; i < n; i++)
        {

            if (i == current)
            {
                continue;
            }
            if (edges[current][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    delete[] visited;
    return false;
}
int main()
{
    int v, e;
    cin >> v >> e;
    int v1, v2;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    cin >> v1 >> v2;
    if (hasPath(edges, v, v1, v2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
    // Write your code here
}