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
/**********************Optimal Approach for Smallest SubTree With All Deepest Node*************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {
    pair<TreeNode * , int> height(TreeNode * root  ,int h) {
        if(root == NULL)
            return { NULL , 0}  ;
        
        auto lh = height(root -> left ,  h + 1 );
        auto rh = height(root -> right ,  h + 1 );
        int d1 = lh.second , d2 = rh.second;
        
        
         return {d1 == d2 ? root : d1 > d2 ? lh.first : rh.first , max(d1 , d2) + 1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int h = 0;
        auto ans =  height(root , h);
        return ans.first;
    }
};