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
/**********************Optimal Approach for Lowest Common Ancestor of Deepest Leaves*************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {
    int height(TreeNode * root , TreeNode *&ans ,int h ,  int &deepest) {
              if( root == NULL )
                  return h;
        int left = height(root -> left , ans , h + 1 , deepest);
        int right = height(root -> right , ans , h + 1 , deepest);
        
        deepest = max(deepest , max(left , right) );
       
        if(left == deepest && right == deepest) {
             cout<<left <<" " <<right<<" "<<deepest<<" ";
            ans = root;
            cout<<ans -> val<<endl;
        }
            
        
        return max(left , right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode * ans = NULL;
        int h = 0  , deepest = 0;
        height(root , ans , h , deepest);
        return ans;
    }
};