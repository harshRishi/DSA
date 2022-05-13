#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> getPath_BFS(int **edges, int v, int s, int e, bool *visited)
{
    vector<int> ans;
    if (s == e)
        return ans;

    // create queue to store the pendingvertices
    queue<int> pendingVertices;
    pendingVertices.push(s); // push the starting vertex
    visited[s] = true;

    // make a unordered_map to store the key and value (key - ith vertex, value - currentVertex)
    unordered_map<int, int> map;
    map[s] = -1;
    int currentVertex = s;
    while (currentVertex != e && !pendingVertices.empty()) // run untill we reach the end vertex && pendingVertices shouldn't be empty
    {
        currentVertex = pendingVertices.front(); // saved the front element
        pendingVertices.pop();                   // remove front element

        // push the adjacent of s and so on
        int i;
        for (i = 0; i < v; i++)
        {
            if (i == currentVertex) // 0 ka 0 k sath edge it's not to be calc so skip
                continue;

            // if we have any edge at [front][i] && before pushing-in, check if visited or not
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                map[i] = currentVertex; // ith vertex is been pushed by currentVertex
                visited[i] = true;      // marked visited
            }
        }
    }
    if (map.count(e) > 0) // map.count is a function which checks wheather e is present in map or not, ie. if not = 0, if yes = 1
    {
        ans.push_back(e);
        int temp = map[e];
        while (temp != -1)
        {
            ans.push_back(temp);
            // int t=temp;
            temp = map[temp];
        }
    }
    return ans;
}

int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;

    // create a v size graph matrix
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++) // initially no connection
            edges[i][j] = 0;
    }

    // now collect the edges information
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1; // connnected
        edges[b][a] = 1; // connected
    }

    // take source and distination
    int source, destination;
    cin >> source >> destination;

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false; // initially not visited any place
    }

    vector<int> result = getPath_BFS(edges, v, source, destination, visited);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    delete[] visited;
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}