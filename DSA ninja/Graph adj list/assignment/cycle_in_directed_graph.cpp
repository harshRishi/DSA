#include <bits\stdc++.h>
using namespace std;

bool check(vector<vector<int>> &adj, vector<int> &vis, vector<int> visDfs, int sv)
{ // here we've not pass visDfs by ref as we don't want to sve it
    vis[sv] = 1;
    visDfs[sv] = 1;
    for (auto &it : adj[sv])
    {
        if (!vis[it]) // not visited
        {
            if (check(adj, vis, visDfs, it))
                return true;
        }
        else if (visDfs[it]) // this means both are visited at the same time
            return true;
    }
    return false;
}

bool cycle_in_directed(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n + 1, 0);
    vector<int> visDfs(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (check(adj, vis, visDfs, i))
            {
                return true;
            }
        }
    }
    return false;
}
int32_t main()
{
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // only u -> v as the graph is directed
        }
        cout << (cycle_in_directed(adj) ? "YES" : "NO");
    }
}

/* // ans = no
9 9
1 2
2 3
3 4
4 5
3 6
6 5
7 2
7 8
8 9

ans = yes
9 10
1 2
2 3
3 4
4 5
3 6
6 5
7 2
7 8
8 9
9 7
*/
