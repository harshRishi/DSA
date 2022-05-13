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

// consider ll to be 1-2-3-4-5-null; and  n = 3

int lLength(Node *head) // finding length of Linked List
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    int breakPoint = lLength(head) - n;
    if (breakPoint < 0 || n == 0) // n is greater than the LL length or n == 0
    {
        return head;
    }
    Node *temp = head;
    for (int i = 1; i < breakPoint; i++) // uploading temp with breakPoint address
    {
        temp = temp->next;
    }
    Node *newHead = temp->next; // location temp is on 2 nd having address of 3 while new head have address of 3
    temp->next = NULL;          // here we broke the connection bt 2 nd 3

    Node *temp2 = newHead;
    while (temp2->next != NULL) // uploading temp2 with last element address
    {
        temp2 = temp2->next;
    }
    temp2->next = head;

    head = newHead;
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
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}