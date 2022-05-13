#include <iostream>
#include <cstring>
using namespace std;

// make a 2d matrix i.e 2d array
int chess[11][11]; // set this to 11 * 11 matrix

bool isPossible(int n, int row, int col)
{
    // check Same Column {check if there is any queen in same col0}
    for (int i = row - 1; i >= 0; i--) // row k uper wala element check
    {
        if (chess[i][col] == 1) // this means Queen exist in the same col
            return false;
    }

    // Check Upper Left Diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 1)
            return false;
    }

    // Check Upper Rigth Diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (chess[i][j] == 1)
            return false;
    }

    // if we reached here that means it is the possible position
    return true;
}

void nQueenHelper(int n, int row) // helper which print all the solutions
{
    if (row == n) // In Case we've reached some solution
    {
        // print the matrix and return
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << chess[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    // place at all the possible position and move to smaller problem
    for (int j = 0; j < n; j++)
    {
        // check possibility at row number at jth position
        if (isPossible(n, row, j))
        {
            chess[row][j] = 1;        // place the queen as it is possible
            nQueenHelper(n, row + 1); // recursion on further rows;
            // *** if we reach here that means we have to backTrack *** ??
            chess[row][j] = 0; // remove queen as now it found that that is not a possible postion
        }
    }
    return; // this will return to helper in the call Stack of the recusion than out of the funtion
}

// fucntion that will place the queen in it's possible positions
void placeNQueens(int n) // n is size of the matrix
{
    // using memset function to initial all the position with 0
    memset(chess, 0, 11 * 11 * sizeof(int));
    // arguments (row size and current row number)
    nQueenHelper(n, 0); // a helper function where we can use recurtion with more arguments
}

int main()
{
    placeNQueens(4);
    return 0;
}