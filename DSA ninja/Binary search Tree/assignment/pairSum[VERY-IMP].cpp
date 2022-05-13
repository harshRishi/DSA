#include <algorithm>
#include <vector>

/* Approch */
/*
- first convert the BT to an array // we can use normal arrays but here we've used vector array as they are dynamic in natour
- sort the array (we've used the inbuilt sorting method we can also use merge or quick)
- as the vector is sorted we can take 2 pointer i and j pointing begining and ending of the vector
- here i will represent smaller and j represents larger int
- if the sum is smaller than our Vi + Vj than decrease j so the we add smaller value to i
- if the sum is larger than Vi + Vj than increase i so that we can add larger value of i to the newSUm
- if we found the match than simply print
*/

void buildArray(BinaryTreeNode<int> *root, vector<int> *v)
{
    if (root == NULL)
        return;

    // inorder
    buildArray(root->left, v);
    v->push_back(root->data);
    buildArray(root->right, v);
}

void pairSum(BinaryTreeNode<int> *root, int sum)
{
    // Write your code here
    if (root == NULL)
        return;

    vector<int> *v = new vector<int>();
    buildArray(root, v);

    sort(v->begin(), v->end()); // here we've sorted the vector array;
    int len = v->size();

    for (int i = 0, j = len - 1; i < j;)
    {
        int netSum = v->at(i) + v->at(j);
        if (netSum == sum)
        {
            cout << v->at(i++) << " " << v->at(j--) << endl;
        }
        else if (netSum > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    v->clear();
    delete v;
}