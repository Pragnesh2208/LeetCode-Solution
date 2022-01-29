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
/****************************OPtimal Approach to Invert A Binary Tree *********************************/
/****************************Time Complexity = O(N)***************************************************/
/****************************Space Complexity = O(H)***************************************************/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        invertTree(root -> left);
        swap(root -> left , root -> right);
        invertTree(root -> left);
        return root;
    }
};