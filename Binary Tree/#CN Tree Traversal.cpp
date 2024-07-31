/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void getInorder(TreeNode * root , vector<int>&arr) {
    if(root == NULL) return;
    if(root -> left != NULL) getInorder(root -> left , arr );
    arr.push_back(root -> data);
    if(root -> right != NULL) getInorder(root -> right , arr);
    return;
}
void getPreOrder(TreeNode * root , vector<int>&arr) {
    if(root == NULL) return;
    arr.push_back(root -> data);
    if(root -> left != NULL) getPreOrder(root -> left, arr);
    if(root -> right != NULL) getPreOrder(root -> right, arr);
    return;
}
void getPostOrder(TreeNode * root , vector<int>&arr) {
    if(root == NULL) return;
    if(root -> left != NULL) getPostOrder(root -> left, arr);
    if(root -> right != NULL) getPostOrder(root -> right, arr);
    arr.push_back(root -> data);
    return;
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int>inOrder;
    vector<int>preOrder;
    vector<int>postOrder;
    getInorder(root, inOrder);
    getPreOrder(root , preOrder);
    getPostOrder(root,postOrder);
    return {inOrder , preOrder , postOrder};
    
}