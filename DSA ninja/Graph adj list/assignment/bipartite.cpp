#include <bits\stdc++.h>
using namespace std;

bool check(vector<int> &adj[], vector<int> &color, int sv)
{
    if (color[sv] == 0)
        color[sv] = 1;
    for (auto &it : adj[sv])
    {
        if (color[it] == 0) // adj vertex is not colored
        {
            color[it] = -color[sv];
            if (!check(adj, color, it))
                return false;
        }
        else if (color[it] == color[sv])
            return false;
    }
    return true;
}

/* // bfs
bool check(vector<int> &adj[], vector<int> &color, int sv)
{
    queue<int> q;
    q.push(sv);
    color[sv] = 1; // that is blue color
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto &it : adj[front])
        {
            if (color[it] == 0)
            {
                color[it] = -color[front];
                q.push(it);
            }
            else if (color[it] == color[front])
                return false;
        }
    }
    return true;
}
*/
bool biparted(vector<int> &adj[], int n)
{
    if (n < 3)
        return false;
    vector<int> color(n + 1, 0); // 0 - not colored, 1-blue, -1 -> red
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            if (!check(adj, color, i))
                return false;
        }
    }
    return true;
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
    cout << ((biparted(adj, n) ? "Yes, Graph is biparted" : "No, Graph isn't Biparted");
    return 0;
}
