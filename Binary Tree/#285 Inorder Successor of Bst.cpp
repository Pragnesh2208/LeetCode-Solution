/*********************Optimal Approch for Inorder Successor Of BST**/
/*********************Time complexity = O (N)************************************/
/**********************Space complexity = O (H)**********************************/
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
       TreeNode * ans = NULL;
        while(root != NULL) {
            if(root -> val > p -> val ) {
                ans = root;
                root = root -> left;
            } else {
                root = root -> right;
            }
        }

        return ans;
    }
};