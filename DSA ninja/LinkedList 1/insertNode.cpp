#include <iostream>
using namespace std;
#include "Node.cpp"

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// as we're getting a pointer pointing towards Node we need make this function Node* and as Node * is seperate variable we need to return it.
Node *insertNode(Node *head, int i, int data) // as inked list passes address of the Node so any change in the void will be reflacted in the Main()
{
    Node *newNode = new Node(data); // dry run, very important
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < i - 1) // In case when i have larger value than LL length than our temp will become NUll and we'll exit the loop
    {
        temp = temp->next;
        count++;
    }
    // VERY IMPORTANT //
    if (temp != NULL) // here we don't want to execute the below code if our ll is already exausted
    {
        newNode->next = temp->next; // this should always come before temp->next = newNode if it isn't taken care than we'll lose rest of the ll as now newNode doesn't have the address of the next  Node.
        temp->next = newNode;

        // OR ??
        /*
    Node *a = temp->next;
    temp->next = newNode;
    newNode->next = a; 
    */
    }
    return head;
}

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
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
            tail = tail->next;
            // OR
            // tail = newNode;
        }

        cin >> data;
    }
    return head;
}

int main()
{

    Node *head = takeInput_Better();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i, data);
    print(head);
}