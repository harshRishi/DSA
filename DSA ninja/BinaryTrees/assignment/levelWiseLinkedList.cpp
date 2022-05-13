/*
Apporch:
*Here we're using lvl order traversal where we have a queue which stores lvl wise TreeNodes
*Now TreeNOdes which are on same Level needs to be connected via a LinkedList (for which we've used takeInput type stratgy which following twich)
*if our queue's front element is not NULL than make a newNode, push left right of the tree into the queue(if any) than use head and tail to connect them
*if our queue's front element is NULL than store the head of the Newly created LL into our vector,
after tht Check ** if queue is empty if yes that means our Tree is Over and we dont need to Push NULL further hence we've broke the LOOP
if queue isn't empty than simply push another NULL behind level 
*/

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    // Write your code here
    vector<Node<int> *> v; // here we've created a vector array which we will return
    if (root == NULL)
        return v; // in Case our Tree Have No BInaryTreeNodes

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    while (!q.empty()) // using same strgy as that we have used in the Print Level Wise with lil twich
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front != NULL)
        {
            Node<int> *newNode = new Node<int>(front->data);
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        else // if we got NULL that means are level is over and we need to save the newNode to our vector array and also need to reset head and tail
        {
            v.push_back(head);
            head = NULL; // reset the head for the new Level LinkList so as tail
            tail = NULL;
            if (q.empty()) // this means our Tree is Over
                break;
            q.push(NULL); // here we're defining other levels for further iterations
        }
    }
    return v;
}