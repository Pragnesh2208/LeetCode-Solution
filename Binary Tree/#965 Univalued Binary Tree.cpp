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
/*******************Optimal Approach to Univalued Binary Tree*******************************/
/*******************Time complexity = O(N)*****************************************************/
/*******************Space Complexity = O(H)****************************************************/
class Solution {
public:
     bool isUnivalTree(TreeNode* root, int val = -1) {
        if (!root) return true;
        if (val < 0) val = root->val;
        return root->val == val && isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};