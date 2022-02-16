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
/**********************Optimal Approach to Delete Leaves Nodes with Given Value****************************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {
   
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
       if(root -> left) root -> left = removeLeafNodes(root -> left , target);
       if(root -> right) root -> right = removeLeafNodes(root -> right , target);
         return root -> left == NULL && root -> right == NULL && target == root -> val ? nullptr : root;
        
    }
};
