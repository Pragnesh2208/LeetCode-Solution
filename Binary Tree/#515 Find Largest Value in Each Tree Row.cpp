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
/***********************Optimal Approach For Find A Largest Value in Each Tree Row****************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/

class Solution {
   int getLevel(TreeNode * root , int level = 0) {
       if(root == NULL)
           return level;
       int ll = getLevel(root -> right , level  +1);
       int rl =getLevel(root -> left , level + 1);
       return max(ll , rl);
   }
    void dfs(TreeNode * root , int level  , vector<int>&ans) {
        if(root == NULL)
            return;
        if(ans[level ] < root -> val)
            ans[level ]  = root -> val;
        dfs(root -> left , level + 1 , ans);
        dfs(root -> right , level + 1 , ans);
        
    }
public:
    vector<int> largestValues(TreeNode* root) {
        int level = getLevel(root);
        vector<int>ans(level , INT_MIN);
        dfs(root , 0 , ans);
        return ans;
    }
};