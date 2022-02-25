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
/**********************Optimal Approach for Maximum Level Sum of Binary Tree*************/
/*********************Time complexity = O (N)********************************************/
/**********************Space complexity = O (H)******************************************/
class Solution {
     void level(TreeNode * root , int lev , unordered_map<int , int> & level_sum) {
        if(root == NULL)
            return; 

        level_sum[lev] += root -> val;
        
        level(root -> left , lev +1 , level_sum);

        level(root -> right, lev + 1 , level_sum);
        
    } 
public:
    int maxLevelSum(TreeNode* root) {
        
        unordered_map<int , int > level_sum;
        int Max = INT_MIN;
        int ans;
        level(root , 0 , level_sum);
        for(int i = 0 ; i <level_sum.size() ; i++)
            if(level_sum[i] > Max) {
                ans = i;
                Max = level_sum[i];
            }
        return ans + 1;
    }
};