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

// Function to find the mid of linked-list
Node *find_middle(Node *head, int n)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// Function to Reverse the List using three pointers
Node *reverse_link(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Return if the Linked List is palindrome
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *temp = head;
    // Iterate to count odd/even
    int n = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        n++;
    }
    temp = head;
    // Find the mid elemeny
    Node *head_mid = find_middle(temp, n);
    // Reverse the second half linked-list
    Node *head_rev = reverse_link(head_mid);
    // Verify first half and second half of linked-list are equivalent
    while (head_rev != NULL)
    {

        if (head->data != head_rev->data)
            return false;

        head_rev = head_rev->next;
        head = head->next;
    }
    return true;
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}