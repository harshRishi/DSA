#include <iostream>
#include <vector>
using namespace std;

#include <string>
int l = 0;
void solveHelper(vector<vector<char>> &board, int N, int M, int i, int j, string S, int **visited)
{
    if (S.size() == 0)
    {
        l++;
        return;
    }

    if (i < 0 || i >= N || j < 0 || j >= M)
        return;

    if (visited[i][j] == 1)
        return;

    if (S[0] != board[i][j])
        return;

    visited[i][j] = 1;

    solveHelper(board, N, M, i - 1, j, S.substr(1), visited);
    solveHelper(board, N, M, i + 1, j, S.substr(1), visited);
    solveHelper(board, N, M, i, j - 1, S.substr(1), visited);
    solveHelper(board, N, M, i, j + 1, S.substr(1), visited);
    solveHelper(board, N, M, i + 1, j - 1, S.substr(1), visited);
    solveHelper(board, N, M, i + 1, j + 1, S.substr(1), visited);
    solveHelper(board, N, M, i - 1, j - 1, S.substr(1), visited);
    solveHelper(board, N, M, i - 1, j + 1, S.substr(1), visited);

    visited[i][j] = 0;
}

bool hasPath(vector<vector<char>> &board, int N, int M)
{
    // makeing a visited array;
    string S = "CODINGNINJA";
    int **visited = new int *[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == S[0])
            {
                solveHelper(board, N, M, i, j, S, visited);
                if (l > 0)
                    return true;
            }
        }
    }
    return false;
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

    cout << (hasPath(board, n, m) ? 1 : 0);
}