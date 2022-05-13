#include <iostream>
using namespace std;
#include "BinaryTreeClass.h"

class AVL
{
    BinaryTreeNode<int> root; // class Data member

public:
    // construtor
    AVL()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL)
            return true;
        else
            return false;
    }

    int height(BinaryTreeNode<int> *node)
    {
        if (node == NULL) // base Case ??
            return 0;

        return 1 + max(height(node->left), height(node->right));
    }

    // Get a Balancing factor of Node n
    int getBf(BinaryTreeNode<int> *node) // this will going give left and right height difference
    {
        // Base Case
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    BinaryTreeNode<int> *rightRotation(BinaryTreeNode<int> *node)
    {
        BinaryTreeNode<int> *x = node->left;
        BinaryTreeNode<int> *subTree = x->right;

        // perform  ll rotaion
        x->right = node;
        node->left = subTree;

        return x;
    }

    BinaryTreeNode<int> *leftRotation(BinaryTreeNode<int> *node)
    {
        BinaryTreeNode<int> *y = node->right;
        BinaryTreeNode<int> *subTree = y->left;

        // perform rr Rotation
        y->left = node;
        node->right = subTree;
        return y; // ie, new root node
    }

private: // helper for insert and delete operations
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data)
    {
        // Base Case
        if (node == NULL)
        { // created a new Node any
            BinaryTreeNode<int> *newNode new BinaryTreeNode<int>(data);
            node = newNode;
            return node;
        }

        if (node->data > data) // make a left call and attach it with left of the node(root)
        {
            node->left = insert(node->left, data);
        }
        else if (node->data < data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            cout << "This data member already exist" << endl;
            return node;
        }

        // now as this is a AVL Tree we Need to balance the tree before further oprations
        int bf = getBf(node);
        // LL rotation
        if (bf > 1 && data < node->left->data)
            return rightRotation(node);

        // RR rotation
        if (bf < -1 && data > node->right->data)
            return leftRotation(node);

        // Left Right Case
        if (bf > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (bf < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        /* return the new node pointer */
        return node;
    }

    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *node, int data)
    {
        // Base Case
        if (node == NULL)
            return NULL;

        if (node->data > data) // if data is smaller than search it in the left subTRee
        {
            node->left = remove(data, node->left); // connected new root after recursion of left
        }
        else if (node->data < data) // if data is greter than search in right subTree
        {
            node->right = remove(data, node->right);
        }
        else // ============================= in case we reached the node which we want to delete
        {
            if (node->right == NULL && node->left == NULL)
            { // if both re NULL left and right
                delete node;
                return NULL;
            } // if one of left or either right is NULL
            else if ((node->right == NULL && node->left != NULL) || (node->right != NULL && node->left == NULL))
            {
                if (node->right == NULL)
                {
                    BinaryTreeNode<int> *temp = node->left;
                    node->left = NULL;
                    delete node; // this delete is recusive so we have made node's left NULL to avoid whole tree deletion
                    return temp;
                }
                else
                {
                    BinaryTreeNode<int> *temp = node->right;
                    node->right = NULL; // we've to set node's right = NULL before we delete the node coz'as soon as we call delete it won't delete the whole tree below it as it works on recusion
                    delete node;
                    return temp;
                }
            }
            else
            { // if left and right are non NULL
                BinaryTreeNode<int> *rightMin = node->right;
                while (rightMin->left != NULL) // calculated the minimum
                {                              // this will stop as soon as rightMin's left Become NULL that means we've reached rigthSUbtree's minimum value
                    rightMin = rightMin->left;
                }
                // at this point rightMin is pointing towards minimum of right side
                int temp = rightMin->data; // this will store the minimun value from node's right
                // delete rightMin; // we can't do this as rightMin is a copy of the min from right side of root node calling delete will delete only the copy not the actual minimum if the rightSubTree
                node->right = remove(temp, node->right); // this will delete the mininum node
                node->data = temp;                       // copied the data from temp to our node
                // return node; we'll return it after performing the AVL rotations
            }

            // Now as it is an AVL tree we nned to balance it and return the appropriate node
            // now as this is a AVL Tree we Need to balance the tree before further oprations
            int bf = getBf(node);
            // LL rotation
            if (bf > 1 && data < node->left->data)
                return rightRotation(node);

            // RR rotation
            if (bf < -1 && data > node->right->data)
                return leftRotation(node);

            // Left Right Case
            if (bf > 1 && data > node->left->data)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Right Left Case
            if (bf < -1 && data < node->right->data)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            /* return the new node pointer */
            return node;
        }
    }

public:
    void
    insert(int data) // this function needs a only data which needs to be inserted (like there is AVL newAVlTree, so if we want to insert something we have to write newAVLTree.insert(data);)
    {                // root will come along with "this" keyword
        this->root = insert(this->root, data);
    }

    void remove(int data)
    {
        // Implement the remove() function
        this->root = remove(data, this->root);
    }
}
