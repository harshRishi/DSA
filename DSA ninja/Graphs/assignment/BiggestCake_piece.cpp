
int count_ones(vector<vector<int>> &cake, int n, int i, int j, bool **visited)
{
    int count = 1;
    if (i > 0 && !visited[i - 1][j] && cake[i - 1][j] == 1) // up
    {
        visited[i - 1][j] = true;
        count += count_ones(cake, n, i - 1, j, visited);
    }
    if (j > 0 && !visited[i][j - 1] && cake[i][j - 1] == 1) // left
    {
        visited[i][j - 1] = true;
        count += count_ones(cake, n, i, j - 1, visited);
    }
    if (i < n - 1 && !visited[i + 1][j] && cake[i + 1][j] == 1) // down
    {
        visited[i + 1][j] = true;
        count += count_ones(cake, n, i + 1, j, visited);
    }
    if (j < n - 1 && !visited[i][j + 1] && cake[i][j + 1] == 1) // right
    {
        visited[i][j + 1] = true;
        count += count_ones(cake, n, i, j + 1, visited);
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // create a visited matrix
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
    // search for 1 which is not visited in the cake
    int largestPiece = 0; // reff.. to max piece of cake
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                // mark this location visited
                visited[i][j] = true;
                // call recusion
                int piece = count_ones(cake, n, i, j, visited);
                largestPiece = max(largestPiece, piece); // largestPiece should always be holding max number
            }
        }
    }
    return largestPiece;
}