#include <iostream>
using namespace std;
#include <queue>

void print_BFS(int **edges, int v, int sv, bool *visited)
{
    queue<int> pendingVertices; // queue to hold the vertice so that we can print BFS
    pendingVertices.push(sv);   // as our sv is 0 we print that
    visited[sv] = true;

    while (!pendingVertices.empty()) // till our queue is empty
    {
        int front = pendingVertices.front(); // this will hold current front value
        pendingVertices.pop();               // here we've poped the front element
        cout << front << " ";                // print that value

        for (int i = 0; i < v; i++) // by this loop we've pushed each element in queue which are adjacent to front
        {
            if (i == front) // 0 ka 0 k sath edge it's not to be calc so skip
                continue;

            if (edges[front][i] == 1 && !visited[i]) // if we have any edge at [front][i] && before pushing-in, check if visited or not
            {
                pendingVertices.push(i);
                visited[i] = true; // marked visited
            }
        }
    }
}

void BFS(int **edges, int v)
{
    // create a visited array to store if we've already printed the vertice
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++) // initially we've not visited any vertice
        visited[i] = false;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            print_BFS(edges, v, i, visited); // here i is the starting vertex as graph might be disconnected that means we need search for unvisited vertices after traversal
    }
    // by the end of the loop everything will be visited so now we can delete the visited arry
    delete[] visited;
}

int main()
{
    // Ask user for Number of vertices and number of edges
    int v, e;
    cin >> v >> e;
    // now create adjacency matix of v * v length
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        // Initially mark all the edges false ie, 0
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    // Now take connecting edges from the user
    for (int i = 0; i < e; i++) // i will move till e as it represents the number of edges
    {
        int a, b;
        cin >> a >> b;
        // mark a-b ad true(ie, 1) and mark b-a true as well
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    BFS(edges, v);              // passed our edges matrix and number of vertices
    for (int i = 0; i < v; i++) // delete all the dynamically created matrixes and arrays
        delete[] edges[i];
    delete edges;
}