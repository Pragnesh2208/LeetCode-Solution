/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*********************Optimal Approch for Lowest Common Ancestor of Binary Tree**/
/*********************Time complexity = O (N)************************************/
/**********************Space complexity = O (H)**********************************/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        
        TreeNode * left = lowestCommonAncestor(root -> left , p , q);
        TreeNode * right =lowestCommonAncestor(root -> right , p , q);
        if(root == p || root == q)
            return root;
    if(right && left)
        return root;
        else
            return left ? left : right;
    
    }
};