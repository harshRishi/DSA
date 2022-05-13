#include <bits/stdc++.h>
using namespace std;

void shortDist(vector<vector<int>> &adj, int si)
{
    int n = adj.size();
    vector<int> distArr(n, INT_MAX);
    queue<int> q;

    distArr[si] = 0; // soruce itself
    q.push(si);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &it : adj[node])
        {
            if (distArr[node] + 1 < distArr[it])
            {
                distArr[it] = distArr[node] + 1;
                q.push(it);
            }
        }
    }
    for (auto &t : distArr)
    {
        cout << t << " ";
    }
    cout << '\n';
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int si, ei;
    cin >> si;
    shortDist(adj, si);
    return 0;
}

/*
8 8
0
0 1
0 2
1 3
3 2
2 4
4 5
5 6
5 7
*/