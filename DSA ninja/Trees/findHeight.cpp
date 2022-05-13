int getHeight(TreeNode<int>* root) {
    // Write your code here
    int max = 0;
    for(int i = 0; i < root->children.size(); i++){
        int height = getHeight(root->children[i]); // rc
        
        if(height > max) {
            max = height;
        }
    }
    return max + 1;
}