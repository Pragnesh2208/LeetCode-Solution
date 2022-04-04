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
/*********************Optimal Approch for Path  Sum II**/
/*********************Time complexity = O (N)************************************/
/**********************Space complexity = O (H)**********************************/
class Solution {
    void dfs(TreeNode *root , int sum , vector<vector<int>> &ans , vector<int>arr) {
        if(root == NULL)
            return;
        arr.push_back(root -> val);
        dfs(root -> left , sum - root ->val , ans , arr);
       
        dfs(root -> right , sum - root -> val , ans ,arr);
        cout<<sum<<endl;
        if(root -> left == NULL && root -> right == NULL && sum - root -> val == 0) {
            ans.push_back(arr);
        }
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> path;
        vector<int>arr;
        dfs(root , targetSum , path , arr);
        return path;
    }
};