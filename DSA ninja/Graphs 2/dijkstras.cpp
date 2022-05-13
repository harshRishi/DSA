#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *distances, bool *visited, int n)
{
    // lets say Min vertex Index be -1;
    int minDistIndex = -1;
    for (int i = 0; i < n; i++)
    {
        /*check :
            - not of visited should be true
            - if distance at i is less than i distance at minDistIndex than update minDistIndex with i
            - if minDistIndex is -1 dont reach distances[minDistIndex]
            -
        */
        if (!visited[i] && (minDistIndex == -1 || distances[i] < distances[minDistIndex]))
        {
            minDistIndex = i;
        }
    }
    return minDistIndex;
}

void dijkstras(int **edges, int n)
{
    // create visited array
    bool *visited = new bool[n];
    int *distances = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;     // initially nothing is visited
        distances[i] = INT_MAX; // intially let's say cost of path is INT_MAX so that we can fins min cost path
    }

    // we know distances of source vertex to itself is zero
    distances[0] = 0;

    // pick a minDistVertex
    for (int i = 0; i < n - 1; i++) // n -1 coz last vertex neighbour are alredy been visited no need to run the loop
    {
        // take the source and mark it visited
        int minDistIndex = findMinVertex(distances, visited, n);
        visited[minDistIndex] = true; // mark visited

        // check neighbours of minDistIndex
        for (int j = 0; j < n; j++)
        {
            // check if there is an edges and visited is not true
            if (edges[minDistIndex][j] != 0 && !visited[j])
            {
                // calculate distance from source to neighbour vertex
                int dist = distances[minDistIndex] + edges[minDistIndex][j];
                // check if dist at jth index is less than dist we calculate
                if (distances[j] > dist)
                {
                    // update the vertex distance
                    distances[j] = dist;
                }
            }
        }
    }

    // print the output ie vertex and it's distance from source
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distances[i] << endl;
    }

    // delete all dynamically created variables
    delete[] visited;
    delete[] distances;
}

int main()
{
    // ask user for vertices and edges
    int n, e;
    cin >> n >> e;

    // create a adjacency matrix
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0; // no edges initially
    }

    // ask user for vertices and weight bw them
    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        // wi=eight bw v1 nd v2 is w
        edges[v1][v2] = w;
        edges[v2][v1] = w;
    }
    cout << endl;
    dijkstras(edges, n);

    // delete edges
    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete edges;
    return 0;
}