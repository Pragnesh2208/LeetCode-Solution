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
/***********************Recurive Brute Force Approach to Find Minimum Absolute Difference in BST******************/
/************************Time Complexity = O(N)********************************************************/
/************************Space Complexity = O(H)******************************************************/

class Solution {
    private :
    int prev = -1;
    private:
    void inorder(TreeNode * root , int &ans) {
      if(root -> left) inorder(root -> left , ans);
        if(prev!= -1) {
            ans = min(ans , root -> val - prev);
        
        }
        prev = root -> val;
      if(root -> right) inorder(root -> right , ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        inorder(root , ans);
        return ans;
    }
};
/*****************Optimal Approach to Find Minimum Absolute Difference in BST using Morris Traversal******************/
/******************************Time Complexity = O(N)********************************************************/
/*******************************Space Complexity = O(1)******************************************************/
class Solution {
    private:
    TreeNode * inorder(TreeNode * root , int &ans) {
        
        if(root -> left)
        {
             TreeNode * left = inorder(root -> left , ans);
            ans = min(ans , abs(root -> val - left -> val));    
        }
        if(root -> right) {
             TreeNode * right = inorder(root -> right , ans);
         ans = min(ans , abs(root -> val - right -> val));  
        }
        return root;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        inorder(root , ans);
        return ans;
    }
};