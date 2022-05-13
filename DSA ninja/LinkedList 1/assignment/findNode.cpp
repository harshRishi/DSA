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

// int findNode(Node *head, int n) // METHOD 1 // itrative solution
// {
//     // Write your code here.
//     Node *temp = head;
//     int count = 0;
//     while (temp != NULL)
//     {
//         if (temp->data == n)
//         {
//             return count;
//         }
//         temp = temp->next;
//         count++;
//     }
//     return -1;
// }

int helper(Node *head, int n, int pos) // METHOD 2 // recursive solution
{
    if (head == NULL)
        return -1;

    if (head->data == n)
    {
        return pos;
    }

    int ans = helper(head->next, n, pos + 1);
    return ans;
}

int findNode(Node *head, int n)
{
    return helper(head, n, 0);
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNode(head, val) << endl;
    }
}