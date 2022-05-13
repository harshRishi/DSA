/*
    Note:
    To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
    This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
    down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include <bits/stdc++.h>
using namespace std;

// print the given matirx
void printSolution(int **solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}
void mazeHelp(int maze[][20], int n, int **solution, int x, int y)
{

    // IN case we reached the destination
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1; // include the destination point in the path {ie, make solution for x and y == 1}
        printSolution(solution, n);
        solution[x][y] = 0; // this is not imp as destination point is always going to be 1  but let's for sake make it 0
        return;
    }
    // Now Check if we can move or not
    if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
    {
        return; // return to the call stack
    }
    solution[x][y] = 1; // first include the initial position of rat in the solution matrix
    // Now Move the Rat in the differrnt directions {Top, Down, Left, Right.}
    mazeHelp(maze, n, solution, x - 1, y); // Top
    mazeHelp(maze, n, solution, x + 1, y); // Down
    mazeHelp(maze, n, solution, x, y - 1); // Left
    mazeHelp(maze, n, solution, x, y + 1); // Right
    // now BackTrack and make the current location available for more possible paths {ie. make solution@xy = 0}
    solution[x][y] = 0;
}
void ratInAMaze(int maze[][20], int n)
{
    // make A solution matrix
    int **solution = new int *[n]; // this is how we make a 2d dynamic array
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }
    // Initialization of solution 2D array with 0
    for (int i = 0; i < n; i++)
    {
        memset(solution[i], 0, n * sizeof(int));
    }
    // call helper function
    mazeHelp(maze, n, solution, 0, 0);
}

int main()
{
    // Write your code here
    int n;
    cin >> n;

    int maze[n][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int path;
            cin >> path;
            maze[i][j] = path;
        }
        cout << endl;
    }
    ratInAMaze(maze, n);

    return 0;
}
