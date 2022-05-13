#include <iostream>
using namespace std;

template <typename T>
class Node // this is our template type Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head; // this should be private
    int size;
    // Define the data members
public:
    Stack()
    {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return size == 0;
    }

    void push(T element)
    {
        // Implement the push() function
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        // Implement the pop() function
        if (isEmpty()) // in case there is no Node in our LL
        {
            return -1;
        }
        T ans = head->data;   // save head value in ans
        Node<T> *temp = head; // created pointer pointing towards head
        head = head->next;
        delete temp; // dealocated head;
        size--;
        return ans;
    }

    T top()
    {
        // Implement the top() function
        if (isEmpty()) // in case there is no Node in our LL
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Stack st;

    int q;
    cin >> q;

    while (q--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            st.push(input);
            break;
        case 2:
            cout << st.pop() << "\n";
            break;
        case 3:
            cout << st.top() << "\n";
            break;
        case 4:
            cout << st.getSize() << "\n";
            break;
        default:
            cout << ((st.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}