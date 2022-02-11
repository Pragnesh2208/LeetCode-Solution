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
/*********************Optimal Approach for This problem*****************************/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    private:
    void inorder(TreeNode * root  , int &sum) {
        if(root == NULL)
            return ;
        inorder(root -> left , sum);
        if(root -> val % 2 == 0) {
            if(root -> left ) {
                if(root -> left -> left) 
                     sum += root -> left -> left -> val;
            if(root -> left -> right) 
                sum += root -> left -> right -> val;
            } 
             if(root -> right ) {
                if(root -> right -> left) 
                     sum += root -> right -> left -> val;
            if(root -> right -> right) 
                sum += root -> right -> right -> val;
            } 
        }
        inorder(root -> right  , sum);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        inorder(root , sum);
        return sum;
    }
};