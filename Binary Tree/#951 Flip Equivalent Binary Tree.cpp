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
/**********************Optimal Approach for Flip Equivalent Binary Tree*************/
/*********************Time complexity = O (N)********************************************/
/**********************Space complexity = O (H)******************************************/
class Solution {
    
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL || root2 == NULL)
            return root1 == NULL && root2 == NULL;
        if(root1 -> val != root2 -> val)
            return false;
           
        bool l = flipEquiv(root1 -> left , root2 -> left) && flipEquiv(root1 -> right , root2 -> right);
        
        return l || flipEquiv(root1 -> left , root2 -> right) && flipEquiv(root1 -> right , root2 -> left);
    }
};