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
/***********************Recurive Optimal Approach To find Diameter of Binary Tree******************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    private:
    int inorder(TreeNode * root , int &ans) {
        if(root == NULL)
            return 0;
        int left = inorder(root -> left , ans);
        int right = inorder(root -> right , ans);
        ans = max(ans , left + right);
        return (max(left , right) + 1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        inorder(root , ans);
        return ans;
    }
};