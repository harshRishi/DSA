// only used for Directed Acyclic Graphs
#include <bits/stdc++.h>
using namespace std;

void topoUtilDfs(vector<vector<int>> &adj, int sv, vector<int> &vis, stack<int> &stk)
{
    vis[sv] = 1;
    for (auto &it : adj[sv])
    {
        if (!vis[it]) // not visited
        {
            topoUtilDfs(adj, it, vis, stk);
        }
    }
    stk.push(sv);
}

vector<int> topoSort(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n + 1, 0), result;
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoUtilDfs(adj, i, vis, stk);
        }
    }

    while (!stk.empty())
    {
        int a = stk.top();
        result.push_back(a);
        stk.pop();
    }
    return result;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = topoSort(adj);
    return 0;
}