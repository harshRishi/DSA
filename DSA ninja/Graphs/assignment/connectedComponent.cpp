#include <bits/stdc++.h>
using namespace std;

vector<int> connectedComponent(int **edges, int v, int sv, bool *visited)
{
    // create a vector
    vector<int> component;
    component.push_back(sv);

    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty())
    {
        int cv = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < v; i++)
        {
            if (i == cv)
                continue;

            if (edges[cv][i] == 1 && !visited[i])
            {
                // insert the element int he queue
                pendingVertices.push(i);
                component.push_back(i); // inserted a vertex connected to sv
                visited[i] = true;
            }
        }
    }
    sort(component.begin(), component.end());
    return component;
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
        edges[a][b] = 1; // connected
        edges[b][a] = 1; // connected
    }

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false; // initially not visited any place
    }

    // create an 2d vector matrix
    vector<vector<int>> ans;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            // cout << i << " ";
            vector<int> temp; // this will point the vector component so that later we can store that in the ans
            temp = connectedComponent(edges, v, i, visited);
            ans.push_back(temp);
        }
    }

    // print the ans
    for (int i = 0; i < ans.size(); i++)
    {
        vector<int> component = ans.at(i);
        for (int j = 0; j < component.size(); j++)
        {
            cout << component.at(j) << " ";
        }
        cout << endl;
    }

    // delete all dynamically creted variable
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
    return 0;
}

///===================================
/*
#include <iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;


vector<int> bringComponent(int** edges, int n, int sv, int* visited){
    vector<int> eachC;
    // eachC.push_back(sv);
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;

    while(!q.empty()){
        eachC.push_back(q.front());
        q.pop();
        for(int i = 0; i < n; i++){
            if(edges[sv][i] && visited[i]==0){
                q.push(i);
                visited[i] = 1;
            }
        }
        sv = q.front();
    }
    sort(eachC.begin(), eachC.end());
    return eachC;
}
void allConnectedComponents(int **edges, int n, int* visited){

    for(int i = 0; i < n; i++){
        if(visited[i]==0){
            vector<int> ans = bringComponent(edges,n, i, visited);
            for(int i = 0; i < ans.size(); i++){
                cout<<ans[i]<<" ";
            }

            cout<<endl;
        }
    }
}
int main() {

    int n;
    int e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++){
        int v1,v2;
        cin>>v1>>v2;

        edges[v1][v2] = 1;
        edges[v2][v1] = 1;
    }

    int *visited = new int[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    allConnectedComponents(edges, n, visited);
}
*/