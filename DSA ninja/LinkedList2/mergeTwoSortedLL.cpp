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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    if (head1 == NULL) // for the edge case where one the Linked list is empty
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (finalHead == NULL && finalTail == NULL)
        {
            if (head2->data > head1->data) // for the first iteration
            {
                finalHead = head1;
                finalTail = head1;
                head1 = head1->next;
            }
            else
            {
                finalHead = head2;
                finalTail = head2;
                head2 = head2->next;
            }
        }
        else
        {
            if (head2->data > head1->data) // for rest of the iteration untill one of the LL expires
            {
                finalTail->next = head1; // directing the tail to point to the samller head
                finalTail = head1;       // moving tail to the smaller head
                head1 = head1->next;     // moving samller head to move futher in their perticular LL.
            }
            else
            {
                finalTail->next = head2;
                finalTail = head2;
                head2 = head2->next;
            }
        }
    }
    // If any of the LL is left
    if (head1 != NULL)
    {
        finalTail->next = head1;
    }
    if (head2 != NULL)
    {
        finalTail->next = head2;
    }

    return finalHead;
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
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}