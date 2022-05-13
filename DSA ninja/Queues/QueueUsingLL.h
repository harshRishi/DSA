class Queue
{
    // Define the data members
    Node *head;
    Node *tail;
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

    void enqueue(int data)
    {
        // Implement the enqueue() function
        Node *newNode = new Node(data); // created a New Node as enqueue is called
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

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        // Implement the dequeue() function
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    int front()
    {
        if (isEmpty()) // in case there is no Node in our LL
        {
            return -1;
        }
        // Implement the front() function
        return head->data;
    }
};