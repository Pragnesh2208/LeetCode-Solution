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
/**********************Optimal Approach to Count Good Nodes in Binary Tree*************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution { 
    private:
    void dfs(TreeNode * root , int &count , int  Max) {
        if(root == NULL)
            return;
        if(root -> val >= Max) {
            Max = root -> val;
            count++;
        }
        dfs(root -> left , count , Max);
        dfs(root -> right , count , Max);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        int Max = INT_MIN;
        dfs(root , count , Max);
        return count;
    }
};