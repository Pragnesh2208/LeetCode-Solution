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
/***********************Recurive Optimal Approach For Balanced Binary Tree******************************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    private:
    int height(TreeNode * root , bool &ans) {
        if(root == NULL)
            return 0;
        int left = height(root -> left , ans);
        int right = height(root -> right , ans);
        if(abs(left - right) > 1)
            ans = false;
        return max(left , right)+ 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        height(root  , ans);
        return ans;
    }
};