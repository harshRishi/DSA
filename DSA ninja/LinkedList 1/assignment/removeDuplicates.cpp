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
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    //Write your code here
    Node *temp = head;
    while (temp->next != NULL) // we don't need to check the last element as if it is a duplicate it had already been skipped and the 2nd last element now should be pointing towards the NULL
    {
        Node *nextOne = temp->next;
        if (nextOne->data == temp->data)
        {
            Node *nxtToNxt = nextOne->next;
            temp->next = nxtToNxt;
            nextOne->next = NULL;
            delete nextOne;
            continue; // to skip the below code we have to do this otherwise temp will move twice
        }
        temp = temp->next;
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
        head = removeDuplicates(head);
        print(head);
    }
    return 0;
}