#include <iostream>
#include <cstdlib>

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

Node *swapNodes(Node *head, int i, int j)
{
    //Write your code here
    if (head == NULL || head->next == NULL) // if there is No or Only One Node
        return head;

    int count1 = 0, count2 = 0;
    Node *p1 = head, *c1 = NULL, *p2 = head, *c2 = NULL;

    while (count1 < i - 1) 
    {
        p1 = p1->next;
        count1++;
    }
    c1 = p1->next;
    while (count2 < j - 1)
    {
        p2 = p2->next;
        count2++;
    }
    c2 = p2->next;
    if (c1 == p2)
    { // ci == pj
        p1->next = c2;
        p2->next = c2->next;
        c2->next = p2;
        return head;
    }

    Node *tail = c1->next;
    p2->next = c1;
    p1->next = c2;
    c1->next = c2->next;
    c2->next = tail;
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
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}