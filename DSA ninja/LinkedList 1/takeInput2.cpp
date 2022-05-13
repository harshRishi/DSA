#include <iostream>
using namespace std;
#include "Node.cpp" 

// ================= HERE WE'VE IMPROVED THE TIME COMPLEXCITY OF THE LINKED LIST FORMATION

Node *takeInput2() // this function will going to return a pointer which is of type Node
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL) // for the first Node Only;
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail ->next = newNode;
            tail = newNode; // OR ?? tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

// make sure to dry run if found any confusion while head->next and head != NUll
void print(Node *head) // here head is a node pointer
{
    Node *temp = head; // we've created temp so that we don't loose our head pointer
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // here we're assigning our head as next address which will go on untill we find NULL which is our tail node
    }
    cout << endl;
}

int main()
{
    Node *headI = takeInput2();
    print(headI);

    // Statically creating the node for our linked list
    Node n1(1);
    Node *head = &n1; // HEAD pointer
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);

    /* ----------------VERY IMPORTANT------------------
    // here we've not created any Node as it is just defining that this pointer is just pointing towards a node. just like we write int when any pointer is pointing towards an interger vairable
    n1.next = &n2; // here we have connected both the nodes by copying address of n2 to the n1.next.

    // Dynamically creating the node for our linked list
    Node *n3 = new Node(10);
    Node *head2 = n3; // here n3 is already a pointer so it is already storing address of node n3 thus no need to write &n3

    Node *n4 = new Node(20);
    n3->next = n4;// here n4 is already a pointer so it is already storing address of node n4 thus no need to write &n4
    */

    Node *n6 = new Node(10);
    Node *headD = n6; // head pointer
    Node *n7 = new Node(20);
    Node *n8 = new Node(30);
    Node *n9 = new Node(40);
    Node *n10 = new Node(50);

    n6->next = n7; // here we havent wrote &n7 as it is a pointer so it is already holding address
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    print(headD);
}