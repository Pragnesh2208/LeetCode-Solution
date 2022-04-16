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


/***********************Optimal Approach for Find Smallest String From Leaf************/
/************************Time Complexity = O(N)****************************************/
/************************Space Complexity = O(h)***************************************/
class Solution {
    void dfs(TreeNode * root , string &ans , string str)  {
        if(root == NULL) return;
        char temp = char('a' + root -> val);
        if(!root -> left && !root -> right) {
            ans = min(ans , temp + str);
            return;
        }
        dfs(root -> left , ans , temp  + str);
        dfs(root -> right , ans , temp + str);
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {

        string ans = "~";
        dfs(root , ans , "");
        return ans;
        
    }
};