#include <iostream>
using namespace std;

int cycleOf3(int **edges, int v) // doing this question iteratively
{
    int count = 0;

    // loop 1
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++) // loop 2 ?? find edges corresponding to ith vertex
        {
            if (i == j) // one vertex cannot have edges
                continue;

            if (edges[i][j] == 1) // if there is a vertex check if that vertex have edge with i or not
            {
                for (int k = 0; k < v; k++)
                {
                    if (k == i || k == j) // k ==j represent same vertex || k == i , as we dont have visited here so we need to manually skip the edge with parent itseft to stop infinite loop bw parent and child edge
                        continue;

                    if (edges[j][k] == 1) // check if ith adjacent have edge with i or not
                    {
                        if (edges[k][i]) // check if k also have edges with i if yes than increase the count as there we found a cycle of 3 (i-j-k) in the graph
                            count++;
                    }
                }
            }
        }
    }
    return count; // this count will count each cycle 6 time so before printing the count divide it by 6
}
int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;

    // create edges matrix
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
            edges[i][j] = 0; // defining no edges yet
    }

    // ask user for edges
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        // make an edge bw v1 and v2 (undirected graph so make vice versa edge)
        edges[v1][v2] = 1;
        edges[v2][v1] = 1;
    }

    // we dont requre the visited here
    cout << cycleOf3(edges, v) / 6 << endl; // here we've divided ans by 6 as each cycle in the graph is counted  6 time (dry run for clearity)
}