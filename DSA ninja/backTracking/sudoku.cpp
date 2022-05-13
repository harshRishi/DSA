#include <bits/stdc++.h>
using namespace std;
#define N 9

void print(int **grid)
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
            ;
        }
        cout << endl;
    }
}

bool isRowSafe(int **grid, int row, int data)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == data)
        { // in CAse we found the same data in the row than simply return false
            return false;
        }
    }
    return true;
}

bool isColSafe(int **grid, int col, int data)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == data)
            return false;
    }
    return true;
}

bool isGridSafe(int **grid, int row, int col, int data)
{
    int rFactor = row - (row % 3); // this is the method to find row starting point
    int cFactor = col - (col % 3); // same as that of column
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        { // check our 3*3 matrix
            if (grid[i + rFactor][j + cFactor] == data)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int **grid, int row, int col, int data)
{
    if (isRowSafe(grid, row, data) && isColSafe(grid, col, data) && isGridSafe(grid, row, col, data))
    {
        return true;
    }
    return false;
}

bool solveSudoku(int row, int col, int **grid)
{
    // find the inset location ?? block with zero data
    if (col >= 9 && row == 8)
    {
        // that means we have filled entirely
        // thats why we have come to this stage
        return true;
    }
    else if (col >= 9 && row < 8)
    {
        col = 0;
        row++;
    }

    if (grid[row][col] != 0)
    {
        return solveSudoku(row, col + 1, grid); // if the spot is already filled
        // lets move to the next col
    }
    // By this point our row and col will have empty location's address and we need to fill it with 0 -9 if it is safe to store
    for (int i = 1; i <= N; i++)
    {
        if (isSafe(grid, row, col, i))
        { // i == data to be filled
            grid[row][col] = i;
            if (solveSudoku(row, col + 1, grid))
            {                // check weather the sudoku is solved or not
                return true; // here we are moving on to next col
            }
            grid[row][col] = 0; // backTrack
        }
    }
    // if we couldn't solve even after those 9 values simply return false to the call stack
    return false;
}

int main()
{
    // write your code here
    int **grid = new int *[N]; // this is how we make a 2d dynamic array
    for (int i = 0; i < N; i++)
    {
        grid[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    { // fill matrix
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            grid[i][j] = num;
        }
    }

    solveSudoku(0, 0, grid) ? cout << "true" : cout << "false";

    // print(grid);

    return 0;
}