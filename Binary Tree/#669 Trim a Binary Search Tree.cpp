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
/***********************Optimal Approach For Trim A binary Search Tree******************************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    TreeNode * dfs(TreeNode * root , int &low , int &high ) {
        if(root == NULL)
            return NULL;
       
        root -> left = dfs(root -> left , low , high );
         
        root -> right = dfs(root -> right , low , high);
        
         if(root -> val < low)
            return root -> right;
        if(root -> val > high)
            return root -> left;
        else
            return root;
        
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       return dfs(root , low , high);
       
    }
};