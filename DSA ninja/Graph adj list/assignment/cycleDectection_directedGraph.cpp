// only used for Directed Acyclic Graphs
#include <bits/stdc++.h>
using namespace std;

bool topo_Bfs(vector<vector<int>> &adj, vector<int> &inDegree)
{
    queue<int> q;
    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        count++;
        int node = q.front();
        q.pop();
        for (auto &it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    if (count == adj.size())
        return false;
    return true;
}

bool topoSort(vector<vector<int>> &adj, vector<int> &inDegree)
{
    int n = adj.size();
    vector<int> vis(n, 0), result;
    if (topo_Bfs(adj, inDegree))
        return true;
    return false;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n, 0); // mainting the inDegree here it self
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    bool ans = topoSort(adj, inDegree);
    cout << (ans ? "NO" : "YES");
    return 0;
}

/*
6 6
5 0
5 2
2 3
3 1
4 1
4 0
 ans = 4 5 0 2 3 1 || 5 4 0 3 2 1
*/