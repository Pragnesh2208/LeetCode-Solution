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
/*********************Optimal Approach for Binary Tree Right Side View**************************/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (N )************************************/
class Solution {
    void dfs(TreeNode * root , unordered_map < int , int>&map , int level) {
        if(root == NULL)
            return;
        map[level] = root ->val;
        dfs(root -> left, map , level + 1);
        dfs(root -> right , map , level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int , int > map;
        dfs(root , map , 0);
        vector<int>ans;
        for(int i = 0 ; i < map.size(); i++)
            ans.push_back(map[i]);
        return ans;
    }
};