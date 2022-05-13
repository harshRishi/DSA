#include <iostream>
using namespace std;
#include "Node.cpp"

int length(Node *head) // recursive length
{
    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head;
    int size = 1 + length(temp->next);
    return size;
}

// int length(Node *head) // iterative length
// {
//     //Write your code here
//     Node *temp = head;
//     int count = 0;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         count++;
//     }
//     return count;
// }

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
        cout << length(head) << endl;
    }
    return 0;
}