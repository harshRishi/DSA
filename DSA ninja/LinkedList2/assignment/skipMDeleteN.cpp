#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (M == 0)
    { // in case their is nothing to skip
        return NULL;
    }
    // Write your code here
    Node *temp = head, *t;
    int count;

    while (temp != NULL)
    {
        // Skip M nodes
        for (count = 1; count < M && temp != NULL; count++)
        {
            temp = temp->next;
        }

        // If we reached end of list, then return
        if (temp == NULL)
            return head;

        // Start from next node and delete N nodes
        t = temp->next;

        for (count = 1; count <= N && t != NULL; count++)
        {
            Node *a = t; // here we want to delete this Node i.e temp->next
            t = t->next;
            free(a);
        }
        // Link the previous list with remaining nodes
        temp->next = t;
        // Set current pointer for next iteration
        temp = t;
    }
    return head;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}