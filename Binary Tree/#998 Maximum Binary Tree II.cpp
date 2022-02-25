/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**********************Optimal Approach for Maximum Binary Tree II***********************/
/*********************Time complexity = O (N)********************************************/
/**********************Space complexity = O (H)******************************************/
class Solution {
    private:
 TreeNode*  dfs(TreeNode * root , int & val) {
       if(root && root -> val > val) {
         root -> right = dfs(root -> right , val);
           return root;
       }
        TreeNode *node = new TreeNode(val);
        node -> left = root;
        return node;
    
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
return        dfs(root , val);
    }
};