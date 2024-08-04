/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*********************Optimal Approach for Boundry Traversal***************/
/*********************Time complexity = O (N)******************************/
/**********************Space complexity = O (H)****************************/

class Solution {
public:
    void left(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        if (root->left) {
            ans.push_back(root->val);
            left(root->left, ans);
        } else if (root->right) {
            ans.push_back(root->val);
            left(root->right, ans);
        }
    }
    void bottom(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        bottom(root->left, ans);
        bottom(root->right, ans);
        if (root->left == NULL && root->right == NULL)
            ans.push_back(root->val);
    }

    void right(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        if (root->right) {
            right(root->right, ans);
            ans.push_back(root->val);
        } else if (root->left) {

            right(root->left, ans);
            ans.push_back(root->val);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return {};
        vector<int> ans;
        if (root->left) {
            left(root, ans);
        } else
            ans.push_back(root->val);
        if(root -> left || root -> right)
        bottom(root, ans);
        right(root->right, ans);
        return ans;
    }
};