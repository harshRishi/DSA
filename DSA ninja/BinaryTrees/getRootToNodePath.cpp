#include <vector>
#include <BinaryTreeNodeClass.h>

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    // Base Case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data) // incase our root is the what we need
    {
        vector<int> *output = new vector<int>(); // as this vector we have created is dynamical so we need to use arrow or (*output).operations to access
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput) // if function return a non NULL value than store that perticular root data in this leftOuput else don't thus it will return and no data in that will be printed
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput) // if function return a NON NULL value than doen't matter what output is just push this root data to the rightOutput
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else  // if not found that means it is not presnt in  left nor in right and so as not in root we need to return NULL
    {
        return NULL;
    }
}