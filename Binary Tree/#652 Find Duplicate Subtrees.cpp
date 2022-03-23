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
/*********************Optimal Approch for Find Duplicate Subtrees****************/
/*********************Time complexity = O (N)************************************/
/**********************Space complexity = O (N)**********************************/
class Solution {
    string dfs(TreeNode * root , vector<TreeNode * > &ans , unordered_map<string , int> &map) {
        if(root == NULL) return " ";
        string left = dfs(root -> left , ans , map);
        string right = dfs(root -> right , ans , map);
        
        string str = to_string(root -> val) + " , " +left + " , " + right;
        
        if(map [ str] == 1) ans.push_back(root);
        map[str]++;
        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode * > ans;
        unordered_map<string , int>map;
        dfs(root , ans , map);
        return ans;
    }
};