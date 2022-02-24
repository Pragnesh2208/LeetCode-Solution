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
/**********************Optimal Approach for Kth Smallest Element in BST*************/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    private:
    void inorder(TreeNode * root , int &k , int &ans) {
        if(root == NULL)
            return;
        
        inorder(root -> left , k , ans);
        k--;
        if(k == 0 && ans == -1)
            ans = root -> val;
        inorder(root -> right, k , ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
     inorder(root , k , ans);   
        return ans;
    }
};