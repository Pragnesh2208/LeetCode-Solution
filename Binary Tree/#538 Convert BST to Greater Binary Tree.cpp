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
/***********************Brute Force Approach To Convert BST to greater Binary Tree****************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
   void dfs(TreeNode * root , int &sum) {
        if(root == NULL)
            return ;
       dfs(root -> right , sum );
       root -> val += sum;
       sum = root -> val;
       dfs(root -> left , sum );
       
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root , sum);
        return root;
    }
};
/***********************Optimal Approach To Convert BST to Greater Binary Tree****************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(1)**************************************************/
class Solution {
   void dfs(TreeNode * root , int &sum) {
        
       while(root) {
           if(root -> right == NULL) {
               root -> val += sum;
               sum = root -> val;
               root = root -> left;
           }
           else{
               TreeNode * pre = root ->right;
               while(pre -> left && pre -> left != root)
                   pre = pre -> left ;
               if(pre -> left == root) {
                   pre -> left = NULL;
                   root -> val += sum;
                   sum = root -> val;
                   root = root ->left;
               }
               else{
                   pre -> left = root;
                   root = root -> right;
               }
           }
       }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root , sum);
        return root;
    }
};