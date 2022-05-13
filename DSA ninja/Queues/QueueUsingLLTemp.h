template <typename T>
class Node
{
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    // the data members
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        head = NULL;
        tail = NULL;
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

    void enqueue(T data)
    {
        // Implement the enqueue() function
        Node<T> *newNode = new Node(data); // created a New Node as enqueue is called
        if (head == NULL) // we cannot acess tail->head it is pointing towards NULL that's why we put on the check
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }
        // Implement the dequeue() function
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T front()
    {
        if (isEmpty()) // in case there is no Node in our LL
        {
            return 0;
        }
        // Implement the front() function
        return head->data;
    }
};