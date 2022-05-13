class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

    bool search(int data, BinaryTreeNode<int> *node)
    { // search helper function
        // Base Case
        if (node == NULL)
            return false;

        if (node->data == data)
            return true;

        else if (node->data > data)
        {
            return search(data, root->left);
        }
        else
        {
            return search(data, root->right);
        }
    }

    void print(BinaryTreeNode<int> *node)
    {
        // Base Case
        if (node == NULL)
            return;

        cout << node->data << ":";
        if (node->left)
        {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right)
        {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        print(node->left);
        print(node->right);
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        // Base Case
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (node->data >= data)
        {
            BinaryTreeNode<int> *leftSubTree = insert(data, node->left);
            node->left = leftSubTree;
        }
        else
        {
            BinaryTreeNode<int> *rightSubTree = insert(data, node->right);
            node->right = rightSubTree;
        }
        return node;
    }

    /*APPROCH*/
    /*
    - if root is null simply return NULL
    - if root's data is greater than provided data ? call recusion on left(on smaller Nodes of BST) [caution: root Might Change after RC on left  so attack the left to the root's left]
    - else call recursion on right  [caution: root Might Change after RC on right so attack the right to the root's right]
    - if we get the root's data equal to the provied data that means we need to delete it
    - NOW there are three More cases in deleting a node
    {
        - if both are NULL of the root we want to delete [simply delete the node adn return NULL]
        - if one of them is NULL either left or right[delete the root and return left or right as a new root]
        - if both of them are present {
            - here we first have to find the minimum from the rightSUbTREE of the node
            - copy content to a temp integer variable 
            - call remove funtion on the minimum og th e rightSubTree with node->right
            - than copy the min content to the root node and return root
        }
    }
    */

    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node) // very imp
    {
        // Base Case
        if (node == NULL)
            return NULL;

        if (node->data > data)
        {
            node->left = remove(data, node->left); // connected new root after recursion of left
        }
        else if (node->data < data)
        {
            node->right = remove(data, node->right);
        }
        else
        { // ====================
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
                while (rightMin->left != NULL)
                { // this will stop as soon as rightMin's left Become NULL that means we've reached rigthSUbtree's minimum value
                    rightMin = rightMin->left;
                }
                // at this point rightMin is pointing towards minimum of right side
                int temp = rightMin->data; // this will store the minimun value from node's right
                // delete rightMin; // we can't do this as rightMin is a copy of the min from right side of root node calling delete will delete only the copy not the actual minimum if the rightSubTree
                node->right = remove(temp, node->right); // this will delete the mininum node
                node->data = temp;                       // copied the data from temp to our node
                return node;
            }
        }
    }

public:
    BST()
    {
        // Implement the Constructor
        root == NULL;
    }
    /*----------------- Public Functions of BST -----------------*/

    void remove(int data)
    {
        // Implement the remove() function
        this->root = remove(data, this->root);
    }

    void print()
    {
        // Implement the print() function
        print(root);
    }

    void insert(int data)
    {
        // Implement the insert() function
        this->root = insert(data, this->root);
    }

    bool search(int data)
    {
        // Implement the search() function
        return search(data, root);
    }
};