#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include <stack>

/* APPROCH :-
- first we have made two stacks one which will store r to l so that we can print in order of l to r and other stack is vice Versa
- after this we need to make outer loop such that if one of stacks get empty thorught out the iterations then outer loop will terminate
- inner loop will will run until respective stack is empty
- where we're taking out the first element of the stack and printng them accorrdingly
- after printing the repective element we need to puch childrens of the elment to other stack so that we can print them in reverse order repective to there parents printing order
*/

void zigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    stack<BinaryTreeNode<int> *> s1; // this will store (R-->L) ?? this will allow to print l to right as it is a stack not a queue
    s1.push(root);
    stack<BinaryTreeNode<int> *> s2; // This will store (L-->R)  ?? this will allow to print right to left as it is a stack not a queue

    while ((!s1.empty()) || (!s2.empty())) // run until both of them are empty
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *t1 = s1.top();
            s1.pop();

            if (s1.empty()) // if s1 is empty that means new lIne is required if not than simply print t1
                cout << t1->data << endl;
            else
                cout << t1->data << " ";

            if (t1->left) // push children of the current t1 to the 2nd stack in L to R order so that we can print them in R to left order
                s2.push(t1->left);
            if (t1->right)
                s2.push(t1->right);
        }

        while (!s2.empty())
        {
            BinaryTreeNode<int> *t2 = s2.top();
            s2.pop();

            if (s2.empty()) // if s2 is empty that means new lIne is required if not than simply print t2
                cout << t2->data << endl;
            else
                cout << t2->data << " ";

            if (t2->right) // push children of the current t2 to the 1nd stack in R to L order so that we can print them in L to R order(as s1 and s2 are stacks not queues)
                s1.push(t2->right);
            if (t2->left)
                s1.push(t2->left);
        }
    }
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    zigZagOrder(root);
}