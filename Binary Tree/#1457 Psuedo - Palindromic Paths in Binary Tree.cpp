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
/*********************Optimal Approach for Psuedo - Palindromic Paths in Binary Tree**********/
/*********************Time complexity = O (N)*************************************************/
/**********************Space complexity = O (H)***********************************************/
class Solution {
    int dfs(TreeNode * root ,vector< int> map) {
        if(root == NULL)
            return 0;

       map[root->val]++;

        if(root -> left == NULL && root -> right == NULL) {
              
           int odd = 0 ;
            for(int i= 0 ; i <10;i++) {
             if(map[i] %2 == 1)
                 odd++;
            }
          
            return odd <= 1 ? 1 : 0;
        }
        else {
                
        int ans =  dfs(root -> left  , map ) + dfs(root -> right , map );
         return ans;
        }
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
     vector<int>a(10);
        int ans = 0;
        return dfs(root , a);
        
    }
};