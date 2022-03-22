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
/*********************Optimal Approach for Print Binary Tree****************/
/*********************Time complexity = O (N)********************************/
/**********************Space complexity = O (H)******************************/
class Solution {
    int get_height(TreeNode * root) {
        if(root == NULL)
            return 0;
        int height = max(get_height(root -> left) , get_height(root -> right) ) + 1;
        return height;
    }
    void helper(TreeNode * root, vector<vector<string>> &ans , int level, int l , int r) {
        if(!root) return;
        int mid = l + ( r - l) / 2;
        ans[level][mid] = to_string(root -> val);
        helper(root -> left , ans , level + 1 , l , mid - 1);
        helper(root -> right , ans, level + 1 , mid + 1 ,r);
        return;
    }
    
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = get_height(root);
        // !columns are 2 * height - 1;
        int c = 1<< h ; 
        c -=1;
        vector<vector<string>> ans(h , vector<string>( c ,""));
        helper(root,ans ,0, 0 , c - 1);   
        return ans;
    }
};