#include <iostream>
using namespace std;

// 1 is for true, 0 is for false

// dry run to make it clear [depth_first_search]
void print(int **edges, int v, int sv, bool *visited) // sv - starting vertice
{
    cout << sv << endl; // aate hi print the sv
    visited[sv] = true; // if we've printed an element just mark it visited
    // now using recusion travel the graph
    for (int i = 0; i < v; i++)
    {
        if (i == sv) // as we have already printed sv(starting vertice)
            continue;

        if (edges[sv][i] == 1) // If sv, ith location is true than only print
        {
            // before calling the recusion on ith element check either we have visited this element before, if yes than don't call recustion
            if (visited[i] == true)
                continue;
            print(edges, v, i, visited); // calling recurtion over i as (sv, i) cell is having a 1 which represent true;
        }
    }
}

void DFS(int **edges, int v)
{
    // create a visited array to store if we've already printed the vertice
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++) // initially we've not visited any vertice
        visited[i] = false;

    for (int i = 0; i < n; i++) // a loop to find non visited vertices(if graph is diconnected than passing zero as starting index isn't enough)
    {
        if (!visited[i])
            print(edges, v, i, visited); // here i is the starting vertex as graph might be disconnected that means we need search for unvisited vertices after traversal
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
    // Now print the graph
    DFS(edges, v);              // passed our edges matrix and number of vertices
    for (int i = 0; i < v; i++) // delete all the dynamically created matrixes and arrays
        delete[] edges[i];
    delete edges;
}