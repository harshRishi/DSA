#include <iostream>
using namespace std;
#include "Node.cpp"

// make sure to dry run if found any confusion while head->next and head != NUll
void print(Node *head) // here head is a node pointer
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next; // here we're assigning our head as next address which will go on untill we find NULL which is our tail node
    }
}

int main()
{
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
}
