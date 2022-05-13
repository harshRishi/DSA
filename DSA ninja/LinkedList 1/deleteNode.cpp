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

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.

    if(head==NULL) // In case head is not defined i.e null
    {
        return head;
    }
    
    if (pos == 0) // in case we want to delete the first Node of the LL
    {
        head = head->next;
        return head;
    }

    int count = 0;
    Node *temp = head;
    while (temp->next != NULL && count < pos -1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next != NULL)
    {
        Node *a = temp->next; //moving to the next Node
        Node *b = a->next;
        temp->next = b;
        delete a;
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
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}