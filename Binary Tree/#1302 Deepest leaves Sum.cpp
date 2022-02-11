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
/*********************Optimal Approach for Find Deepest Leaves Sum of Binary Tree********/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    private:
    void inorder(TreeNode * root , int &height , map<int , int > &map , int &MaxH) {
        if(root == NULL)
            return;
       
         map[height] += root -> val;
        MaxH = max(height , MaxH);
        height += 1;
        inorder(root -> left , height , map , MaxH);
        height -= 1;
    height += 1;
        inorder(root -> right, height , map , MaxH);
        height -=1;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int sum = 0 , MaxH = INT_MIN;
        int height = 0;
        map < int , int > map;
        inorder(root , height , map , MaxH);
        return map[MaxH] ;
    }
};