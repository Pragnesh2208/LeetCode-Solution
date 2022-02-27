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
/***********************Optimal Approach to Find Bottom Left Tree Value******************************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    void dfs(TreeNode * root , int & ans , int level , int &deepest) {
        if(root == NULL)
            return ;
       deepest = max(level , deepest);
        if(level == deepest)
            ans = root -> val;
        dfs(root -> right , ans , level + 1 , deepest);
        dfs(root -> left , ans , level + 1 , deepest);
       
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans  , level = 0 , deepest = 0;
        dfs(root  , ans , level , deepest);
        return ans;
    }
};