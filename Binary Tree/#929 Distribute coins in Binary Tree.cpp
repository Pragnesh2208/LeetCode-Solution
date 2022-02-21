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
/**********************Optimal Approach to Distribute Coins in Binary Tree*************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {
    private:
    int dfs(TreeNode * root , int &ans) {
        if(root == NULL)
            return 0;
        int left = dfs(root -> left , ans);
        int right = dfs(root -> right , ans);
        ans += abs(left) + abs(right) ;
        return  left + right + root -> val -1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root , ans);
        return ans;
    }
};