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

class Pair // we made this class to get tail in our reverseLL function to reduce the complexcity of the progm
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLLDoubleNode(Node *head) // Time Complexcity O(n) better
{
    //Write your code here
    // Base case
    if (head == NULL || head->next == NULL)
    {
        // return head; we can't do this now as head is Node while return type is of object with class Pair
        Pair ans; // created an object with class Pair
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    // Rec Call
    Pair roq = reverseLLDoubleNode(head->next); // Asumming the LL is already been reversed
    // small Calc
    roq.tail->next = head; // Attached first Node of the initial ll with the roq last node that is tail Node
    head->next = NULL;     // node head next should point to NULL instead of pointing towards the 2nd Node of initial Linked List

    // very Important to do this
    Pair ans; // created another pair class object. to store head and tail for the recursion to work
    ans.head = roq.head;
    ans.tail = head; // as this head is the first Node of the initial LL so after reversing this ll we need to make this head as tail of our final pair type object i.e ans;

    return ans; // reverse LL new head;
}

Node *reverseLinkedListRec(Node *head)
{
    // reverseLLDoubleNode will give use pair we just took out head out of it
    return reverseLLDoubleNode(head).head; // here we've returned the head from the pair class which holds the value of head and tial so her we only need head
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
