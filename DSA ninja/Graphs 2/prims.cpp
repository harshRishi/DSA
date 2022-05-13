#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weights, bool *visited, int n) // initial Weight array would be < 0 INT_MAX INT_max ... n_times > so for starting min is zero
{
    // set the index of min vertex to be -1 initially
    int minIndex = -1;
    for (int i = 0; i < n; i++)
    {
        /*
        - that index should not be visited
        - if weight at ith index is less than weight at minIndex than return minimum weight index
        - if minIndex is -1 than to update direclty as we know in that case we're accessing weight[-1] which is unnessasary as in that case 0 will be that minvertex
        */
        if (!visited[i] && (minIndex == -1 || weights[i] < weights[minIndex])) // after && operator if minIndex is -1 than compiler won't read 2nd condition as we've used or opertor
            minIndex = i;
    }
    return minIndex;
}

void prims(int **edges, int n)
{
    int *parent = new int[n];       // this stores parent of the current vertex
    int *vertexWeight = new int[n]; // stores vertex weight
    bool *visited = new bool[n];    // check if vertex is vsisted or not
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;        // initially there is no vertex
        vertexWeight[i] = INT_MAX; // initially weight should kept max so that we can min out og all neihbours
    }

    // intializing arrays'
    parent[0] = -1;      // -1 represents 0 is a top level parent
    vertexWeight[0] = 0; // first vertex is of weight zero (let say)

    // pick vertex with minimum weight
    for (int i = 0; i < n - 1; i++)
    {
        // find the min vertex from the graph
        int minVertex = findMinVertex(vertexWeight, visited, n); // here we can use Priority Queue to imporve complexcity to logn but for that we need to make changes when we change vertexWeight in below code
        visited[minVertex] = true; // updated the minVertex to be visited

        // now explore un-visited neihbour
        for (int j = 0; j < n; j++)
        {
            // should have an edge  && that vertex should be unvisted
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                // check if edge-Weight at [minVertex][j] (as we've store w in are adjacency matrix bw vertices) is less than as of vertexWeight at j
                if (edges[minVertex][j] < vertexWeight[j]) // initially {ie in 1st iteration }vertexWeight would be INT_MAX
                {
                    // upadate the vertexWeight at j witb edges[minVertex][j]
                    vertexWeight[j] = edges[minVertex][j];
                    // update parent of jth vertex which will be minVertex itself
                    parent[j] = minVertex;
                }
            }
        }
    }
    // print the output [starting from 1]
    // print formate v1 v2 and weight
    for (int i = 1; i < n; i++) // print vertices and there edge weight (print MST)
    {
        // here i is the vertex and parent is parent[i]
        if (parent[i] < i)
            cout << parent[i] << " " << i << " " << vertexWeight[i] << endl;
        else
            cout << i << " " << parent[i] << " " << vertexWeight[i] << endl;
    }

    delete[] parent;
    delete[] vertexWeight;
    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;

    // here we're using adjacency matrix to store the graph
    int **input = new int *[n]; // TO inprove tha complexcity we can use adjancey list to inporve the time complecity of the program
    for (int i = 0; i < n; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
            input[i][j] = 0; // initially there is no edges
    }

    // ask user for edges and weight
    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        input[v1][v2] = w;
        input[v2][v1] = w;
    }
    cout << endl;
    prims(input, n);

    // delete dynamic variables
    for (int i = 0; i < n; i++)
        delete[] input[i];
    delete[] input;
    return 0;
}