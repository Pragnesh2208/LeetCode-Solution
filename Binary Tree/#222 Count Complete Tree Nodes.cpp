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
/*********************Optimal Approch for Count Complete Tree Nodes****************/
/*********************Time complexity = O (Logn * LOgn)**************************************************/
/*
!AS we will travel left or right side for binary tree which takes logn time and for every call we will find height which is also Logn*/
/**********************Space complexity = O (H)****************************************************/
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int findLeftHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int count = 0;
        while (root)
        {
            count++;
            root = root->left;
        }
        return count;
    }
    int findRightHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int count = 0;
        while (root)
        {
            count++;
            root = root->right;
        }
        return count;
    }
};