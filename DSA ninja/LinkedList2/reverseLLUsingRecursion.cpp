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

Node *reverseLinkedListRec(Node *head) // Time Complexcity O(n^2) very bad
{
    //Write your code here
    // Base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // Rec Call 
    Node *roq = reverseLinkedListRec(head->next); // Asumming the LL is already been reversed
    // small Calc
    Node *temp = roq;
    while (temp->next != NULL)
    {
        temp = temp->next; // travelling to the last Node of the roq ll
    }
    temp->next = head; // Attached first Node with the roq last node
    head->next = NULL; // node head next should point to NULL instead of pointing towards the 2nd Node of initial Linked List

    return roq; // reverse LL new head;
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
        head = reverseLinkedListRec(head);
        print(head);
    }

    return 0;
}