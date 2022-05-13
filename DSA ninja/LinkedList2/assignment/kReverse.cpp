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
// -----------------------------------------------------
class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseFunc(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    // Rec Call
    Pair roq = reverseFunc(head->next);
    // small Calc
    roq.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = roq.head;
    ans.tail = head;

    return ans;
}

Node *kReverse(Node *head, int k)
{
    if (head == NULL || head->next == NULL) // Base Case
    {
        return head;
    }

    //Write your code here
    Node *h1 = head;
    Node *t1 = head;

    // Small Calc.
    for (int count = 1; count < k && t1->next != NULL; count++) // moving t1 to kth position // Warning t1->next should not be null if it is than we can't do t = t->NULL;
    {
        t1 = t1->next;
    }

    Node *h2 = t1->next;
    t1->next = NULL; // from here we get a seperate ll of k length so tht we can reverse it easily

    Pair reversed = reverseFunc(h1); // Our reversed head and tail
    h1 = reversed.head;
    t1 = reversed.tail;

    Node *roq = kReverse(h2, k); // Recursive CAll ------------------

    t1->next = roq;

    return h1;
}
//--------------------------------------------------------------------------

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
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}