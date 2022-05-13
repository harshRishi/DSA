#include <bits/stdc++.h>
using namespace std;
// *********************************************************
int height(vector<vector<int>> &edges, int sv)
{
    int n = edges.size();
    vector<int> visi(n + 1, 0);

    int cnt = 0;
    if (!visi[sv])
    {
        queue<int> q;
        q.push(sv);
        q.push(-1);
        visi[sv] = 1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if (front == -1)
            { // front == null
                cnt++;
                q.push(-1);
            }
            else
            {
                // for(int i = 0; i < edges[front].size(); i++)
                for (auto it : edges[front])
                {
                    if (!visi[it])
                    {
                        q.push(it);
                        visi[it] = 1;
                    }
                }
            }
        }
    }
    return cnt;
}

vector<int> minHeightRoots(vector<vector<int>> &edges)
{
    vector<int> res;
    int n = edges.size();
    int hMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int curr = height(edges, i);
        if (curr < hMin)
        {
            res.clear();
            res.push_back(i);
        }
        else if (curr == hMin)
        {
            res.push_back(i);
        }
    }
    return res;
    // Write your code here.
}
// ///****************************************************
class Runner
{
    int t;
    vector<vector<vector<int>>> edges;

public:
    void takeInput()
    {
        cin >> t;
        edges.resize(t);

        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;
            edges[i].resize(n - 1, vector<int>(2));

            for (int j = 1; j < n; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    cin >> edges[i][j - 1][k];
                }
            }
        }
    }

    vector<vector<vector<int>>> getCopy()
    {
        vector<vector<vector<int>>> edgesCopy;
        edgesCopy = edges;
        return edgesCopy;
    }

    void execute()
    {
        vector<vector<vector<int>>> edgesCopy = edges;

        for (int i = 0; i < t; i++)
        {
            minHeightRoots(edgesCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {

        for (int i = 0; i < t; i++)
        {
            vector<int> ans = minHeightRoots(edges[i]);
            for (int i : ans)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}