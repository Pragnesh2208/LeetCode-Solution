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
/**********************Optimal Approach to Maximum Difference between Node and Ancestor*************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {
  private:
    int dfs(TreeNode * root , int Max , int  Min) {
       if(root == NULL)
           return abs(Max - Min);
       
        Max = max(Max , root -> val);
        Min = min(Min , root -> val);
      int left =  dfs(root -> left , Max , Min);
      int right = dfs(root -> right , Max , Min);
        return max(left , right);
        
    }
public:
    int maxAncestorDiff(TreeNode* root) {
   int Max = INT_MIN , Min = INT_MAX;
        return dfs(root , Max, Min );
    }
};