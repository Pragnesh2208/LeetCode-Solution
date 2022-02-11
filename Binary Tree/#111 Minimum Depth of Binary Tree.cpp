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
/*********************Optimal Approach for Find Minimum Depth of Binary Tree********/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    int inorder(TreeNode * root) {
         
        if(root == NULL)
            return 0;
      
        int left= inorder(root -> left);
        int right = inorder(root -> right);
          if(root -> left == NULL) 
            return 1 + right;
        if(root -> right == NULL)
            return 1 + left ;
        return (min(left , right) + 1);
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return inorder(root);
    }
};