#include <iostream>
#include <vector>
using namespace std;

int l = 0;
void solve(vector<vector<char>> &b, int n, int m, int i, int j, char c, int t, int **d)
{
    // check Limits of the b
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;

    // if we found that there b[i][j] aren't matching char ch that means there is a color misMatch
    if (b[i][j] != c)
        return;

    if (d[i][j] != 0) // if it is zero that means we haven't visited that dot and we should proceed to futher dots exploration
    {
        if (d[i][j] - t + 1 >= 4) // >>> ????
            l++;
        return;
    }
    if (l > 0)
        return;
    // as we're about to call the recusion on adjacant dots so increase the similarDots count number
    t++;
    d[i][j] = t;
    solve(b, n, m, i + 1, j, c, t, d); // down
    solve(b, n, m, i, j + 1, c, t, d); // right
    solve(b, n, m, i - 1, j, c, t, d); // up
    solve(b, n, m, i, j - 1, c, t, d); // left
}

int hasCycle(vector<vector<char>> &b, int n, int m)
{
    // create visited matrix;
    int **d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = new int[m];
        for (int j = 0; j < m; j++)
            d[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m && l == 0; j++) // if cycleCount is 0 bcaz if it is 1 than we can direclty return true
        {
            if (d[i][j] == 0)
                solve(b, n, m, i, j, b[i][j], 0, d);

            if (l > 0)
                break;
        }
    }
    if (l > 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}