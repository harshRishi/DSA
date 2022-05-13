#include <iostream>
using namespace std;

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

int carryOne(Node *head)
{
    if (head == NULL) // Base Case
        return 1;

    // Add carry returned be next node call
    int roq = head->data + carryOne(head->next); // Recursive Call

    head->data = roq % 10; // here we are storing roq first digit to the current head data
    return roq / 10;       // this will return 1 or 0 to the call stack
}

Node *NextLargeNumber(Node *head) // if we want reveser the ll we can use recursion as it works on stacks or you can use stacks explicitly
{
    int carry = carryOne(head);

    if (carry) // this means we have one as carry after adding one to the LL so we need to increse the LL size for example 99 + 1 = 100 so, here we increased on Node
    {
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

/* -----------------------METHODE 2 -------- NON recursive methode---------
Node *NextLargeNumber(Node *head)
{
    // Your Code here
    // return head of list after adding one
    Node *ln = head;
    if (head->next == NULL)
    {
        head->data += 1;
        return head;
    }
    Node *t = head;
    int prev;
    while (t->next)
    {
        if (t->data != 9)
        {
            ln = t;
        }
        t = t->next;
    }
    if (t->data == 9 && ln != NULL)
    {
        if (ln->data == 9 && ln == head)
        {
            Node *temp = new Node(1);
            temp->next = head;
            head = temp;
            t = ln;
        }
        else
        {
            t = ln;
            t->data += 1;
            t = t->next;
        }
        while (t)
        {
            t->data = 0;
            t = t->next;
        }
    }
    else
    {
        t->data += 1;
    }
    return head;
}

// This function mainly uses addWithCarry().
Node *addOne(Node *head)
{
    // Add 1 to linked list from end to beginning
    int carry = addWithCarry(head);

    // If there is carry after processing all nodes,
    // then we need to add a new node to linked list
    if (carry)
    {
        Node *newNode = new Node;
        newNode->data = carry;
        newNode->next = head;
        return newNode; // New node becomes head now
    }

    return head;
}
*/

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
    Node *head = takeinput();

    head = NextLargeNumber(head);
    print(head);
    return 0;
}