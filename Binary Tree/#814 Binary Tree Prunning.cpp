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
/**********************Optimal Approach for Binary Tree prunning*************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {
    bool isBst(TreeNode * root) {
        if(root == NULL)
            return true;
        bool left = isBst(root -> left);
        if(left == true)
            root -> left = NULL;
        bool right = isBst(root -> right);
        if(right == true)
            root -> right = NULL;
       return left && right && root -> val == 0;
            
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return isBst(root) ? NULL :root ;
    }
};