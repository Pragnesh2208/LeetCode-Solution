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

/***********************Optimal Approach Binary Tree Coloring Game*********************/
/************************Time Complexity = O(N)****************************************/
/************************Space Complexity = O(N)***************************************/
class Solution {
    int x_l = 0 , x_r = 0;
    int count(TreeNode * root ,int &x) {
        if(root == NULL)
            return 0;
        
        int l =  count(root -> left , x); 
        int r = count(root -> right , x);
        if(root -> val == x) {
            x_l = l;
            x_r = r;
        }
        return l + r +1;
    }
   
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
       count(root , x);
        return x_l + x_r < n/2 || x_l > n/2 || x_r > n/2;
        
    }
};