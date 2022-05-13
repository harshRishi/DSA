#include <bits\stdc++.h>
using namespace std;

vector<int> print_bfs(vector<int> adj[], int n)
{
    vector<int> bfs;
    vector<int> visited(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                bfs.push_back(front);
                // cout << front << " ";
                for (auto it : adj[front])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

int32_t main()
{
    // n - nodes, m - edges;
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // print_dfs(adj, visited);
    vector<int> bfs = print_bfs(adj, n);
    for (auto it : bfs)
        cout << it << " ";

    return 0;
}
// example :
/*
4 5
0 1
0 2
0 3
1 2
2 3
*/