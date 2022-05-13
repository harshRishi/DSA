#include <bits\stdc++.h>
using namespace std;

bool cycleUtil(vector<vector<int>> &adj, vector<int> &visi, int sv, int parent)
{
    visi[sv] = 1;
    for (auto &it : adj[sv])
    {
        if (!visi[it])
        {
            if (cycleUtil(adj, visi, it, sv))
                return true;
        }
        else if (it != parent)
            return true;
    }
    return false;
}

bool cycleDect(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> visi(n + 1, 0);
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visi[i])
        {
            if (cycleUtil(adj, visi, i, -1)) // i is the curre vertex and -1 is acting parent
            {
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    // n - nodes, m - edges;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << ((!cycleDect(adj)) ? "Yes, cycle Found!" : "No cycle found!");
    return 0;
}
