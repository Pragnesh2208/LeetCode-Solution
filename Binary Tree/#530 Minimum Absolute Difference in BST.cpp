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
    private :
    int prev = -1;
    private:
    void checkPrev(int &prev, int &ans , TreeNode * &root ) {
         if(prev != -1){
                 ans = min(ans , root -> val - prev);
             }
             prev = root -> val;
    }
    void inorder(TreeNode * root , int &ans) {
     while(root){
         if(root -> left == NULL) {
            checkPrev(prev , ans , root);
             root = root -> right;
         }
         else {
             TreeNode * pre = root -> left;
             while(pre -> right && pre -> right != root) {
                 pre = pre -> right;
             }
             if(pre -> right == root) {
                 pre -> right = NULL;
                 checkPrev(prev , ans ,root);
                 root = root -> right;
             }
             else {
                 pre -> right = root;
                 root = root -> left;
             }
         }
     }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        inorder(root , ans);
        return ans;
    }
};