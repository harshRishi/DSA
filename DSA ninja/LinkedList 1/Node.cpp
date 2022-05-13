#include <iostream>
using namespace std;

class Node // this is Node class (baically a user based data type)
{
public:
    int data;   // data for our linked Node
    Node *next; // address of next linked Node

    Node(int data) // by creating this parameterized construtor default construtor is no more visible
    {
        this->data = data;
        next = NULL; // here we've used this keyword as it is not passed in Node object arrgument i.e Node(int data, Node next)..
    }
};