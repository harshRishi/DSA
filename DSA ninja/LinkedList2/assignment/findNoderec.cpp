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

// int findNodeRec(Node *head, int n)
// {
//     //Write your code here
//     int count = 0;
//     Node *temp = head;
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

int helper(Node *head, int n, int i)
{
    if (head == NULL) //  Base Case
    {
        return -1;
    }

    // Small Calc
    if (head->data == n)
    {
        return i;
    }

    return helper(head->next, n, i + 1);
}
int findNodeRec(Node *head, int n)
{
    //Write your code here
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
        cout << findNodeRec(head, val) << endl;
    }
}