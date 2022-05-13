#include <bits/stdc++.h>
using namespace std;
#define fi frist
#define si second

// pair<int, int> first = node, second = weight
// *************************** topo sort function
void topoUtilDfs(vector<vector<pair<int, int>>> &adj, int sv, vector<int> &vis, stack<int> &stk)
{
    vis[sv] = 1;
    for (auto &it : adj[sv])
    {
        if (!vis[it.first]) // not visited
        {
            topoUtilDfs(adj, it.first, vis, stk);
        }
    }
    stk.push(sv);
}
stack<int> topoSort(vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoUtilDfs(adj, i, vis, stk);
        }
    }
    return stk;
}
// ************************** ********************
// main function
void short_dist(vector<vector<pair<int, int>>> &adj, int sr)
{
    stack<int> st = topoSort(adj);
    vector<int> distArr(0, INT_MAX);
    distArr[sr] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // if node never been reached previously
        if (distArr[node] != INT_MAX)
        {
            for (auto &it : adj[node])
            {
                if (distArr[node] + it.second < distArr[it.first])
                    distArr[it.first] = distArr[node] + it.second;
            }
        }
    }
    for (auto &it : distArr)
    {
        (it == INT_MAX) ? cout << "INF " : cout << it << " ";
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w)); // it is a directed graph
    }
    int sr;
    cin >> sr;
    short_dist(adj, sr);

    return 0;
}