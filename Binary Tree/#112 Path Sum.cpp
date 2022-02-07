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
/***********************Recurive Optimal Approach For Path Sum******************************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    void inorder(TreeNode *root , int &sum , bool &ans) {
        if(root == NULL)
            return ;
          
        sum-= root -> val;
        inorder(root -> left , sum , ans); 
        inorder(root -> right , sum , ans);
        
        if(!root -> left  && !root -> right)
            if(sum == 0)
                ans = true;
        sum += root -> val;
    }
   
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        inorder(root , targetSum , ans);
        return ans;
    }
};