#include <bits\stdc++.h>
using namespace std;

void dfs_util(vector<int> adj[], vector<int> &visited, int sv, vector<int> &dfs)
{
    dfs.push_back(sv);
    visited[sv] = 1;
    for (auto it : adj[sv]) // looking for adjacency
    {
        if (!visited[it])
            dfs_util(adj, visited, it, dfs);
    }
}

int32_t main()
{
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
    // int *visited = new int[n + 1]();
    vector<int> visited(n + 1, 0);
    vector<int> dfs;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs_util(adj, visited, i, dfs);
    }
    for (auto it : dfs)
        cout << it << " ";
    // delete[] visited;
    return 0;
}