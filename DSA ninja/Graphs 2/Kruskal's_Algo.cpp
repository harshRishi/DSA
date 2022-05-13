#include <iostream>
#include <algorithm>
using namespace std;

// instead of using union first we can use "unions by rank and path compression" to reduce time complexcity of finding parent

class Edge
{
public:
    // data members
    int v1, v2, w;

    // default construtor
    Edge()
    {
        int v1, v2, w;
    }
    // Parameterized construtor
    Edge(int v1, int v2, int w)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
    }

    // functions
    void printEdge()
    {
        if (v1 < v2)
            cout << this->v1 << " " << this->v2 << " " << this->w << endl;
        else
            cout << this->v2 << " " << this->v1 << " " << this->w << endl;
    }
};

int findParent(int v, int *parent)
{
    if (parent[v] == v) // if index and parent are same that means it is top level parent
        return v;

    return findParent(parent[v], parent); // recusive call
}

bool compare(Edge e1, Edge e2)
{
    return e1.w < e2.w; // this will store INCREASING /*VERY IMPORTANT*/
}

void kruskals(Edge *input, int n, int e)
{
    // As our input array of edges is created successfully thereFore now SORT them in increasing order
    sort(input, input + e, compare); // compare on the basis of weight{ don't use default sort use this compare function to sort }

    // create a output array of edges to store MST (minimum spaning tree) of size n -1. as number of vertices in the MST is (number of vertices in graph - 1)
    Edge *output = new Edge[n - 1];

    // create a parent array to execute the union find
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i; // as intially parent of each index is index itself, afterwards we'll update this arr
    }

    // Maintain a counter that will store the count of edges in output arry
    int count = 0;
    int it = 0;            // this is just a way to iterate over input arry
    while (count != n - 1) // now start filling the output Edge array{untill we reach the MST total edges count}
    {
        Edge currentEdge = input[it++]; // this is the edge with mini weight
        // before adding it to output check?? {union find}
        int p1 = findParent(currentEdge.v1, parent);
        int p2 = findParent(currentEdge.v2, parent);
        if (p1 != p2) // check parent[v1] and parent[v2] are eqaul or not
        {
            output[count++] = currentEdge;
            parent[p1] = p2; // update parents' array ?? considering v2 as parent and v1 as child
        }
    }

    // Print : iterate the whole array
    for (int i = 0; i < n - 1; i++)
    {
        output[i].printEdge();
    }

    delete[] output;
    delete parent;
    return;
}

int main()
{
    // ask user for vertices number and Edge number
    int n, e;
    cin >> n >> e;

    // create a input array of size e (ie. size of total number of edges) which will store edges
    Edge *input = new Edge[e];
    // now fill this arr of edges
    for (int i = 0; i < e; i++)
    {
        // ask user to enter the value of v1 v2 and w
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        // insert these value at there repective postions
        Edge temp(v1, v2, w);
        input[i] = temp;
    }

    kruskals(input, n, e);

    // delete parents array
    delete[] input;
    return 0;
}