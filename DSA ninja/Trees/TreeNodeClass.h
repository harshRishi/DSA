#include <vector>
using namespace std;

// vector is an array which stores Data and TreeNodes(which is Nothing but a pointer pointing to other TreeNodes that are childerns of there repective parent)

template <typename T>
class TreeNode
{
public:
    T data;
    // vector is an dynamic inbuilt array which stores address of childerns
    vector<TreeNode<T> *> children; // here it is not necessary to mention data type of TreeNode as child is of same data type as of their parents.

    // construtor
    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode() // this is a destrutor which is called when we write any delete statment in the main file
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            delete this->children[i]; // this will again call the ~TreeNode() on child TreeNode and this initiated recursion 
        }
    }
};