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
/* Function to reverse the linked list */
void printReverse(Node *head)
{
    // Base case
    if (head == NULL)
    {
        return;
    }

    // print the list after head node
    printReverse(head->next);

    // After everything else is printed, print head
    cout << head->data << " ";
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        printReverse(head);
        cout << endl;
    }
    return 0;
}