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
    Node *tail = head->next; // here head is actually pointing towards 2nd node of the initial LL. so it can be used for our tail to point at the last Node in the reverse linked list
    tail->next = head;
    head->next = NULL;

    return roq;
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