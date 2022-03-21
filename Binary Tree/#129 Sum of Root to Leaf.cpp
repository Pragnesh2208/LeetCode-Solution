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
/*********************Optimal Approach for Sum of Root to Leaf***************/
/*********************Time complexity = O (N)********************************/
/**********************Space complexity = O (H)******************************/
class Solution {
     int dfs(TreeNode * root , int sum) {
         if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL)
            return sum*10 + root -> val ;
       
        sum =sum * 10 + root -> val;
        
       
        int left = dfs(root -> left , sum);
        int right = dfs(root -> right ,sum);
        
        return left + right;
        
    }
public:
    int sumNumbers(TreeNode* root ) {
        
        int sum = 0;
        return dfs(root  , sum);
        
        
    }
};