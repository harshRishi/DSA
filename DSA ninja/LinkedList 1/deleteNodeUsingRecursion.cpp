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

Node *deleteNodeRec(Node *head, int pos)
{
    //Write your code here
    // BASE CASE
    if (head == NULL)
    {
        return head;
    }

    // Small Calc.
    if (i == 0) // here we're directing our head to point to the next elemet and delete the head itself
    {
        head = head->next;
        return head;
    }

    // Recursive Call
    Node *roq = deleteNodeRec(head->next, pos - 1);

    // Now Attack head with roq
    head->next = roq;
    return head;
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
        int pos;
        cin >> pos;
        head = deleteNodeRec(head, pos);
        print(head);
    }

    return 0;
}