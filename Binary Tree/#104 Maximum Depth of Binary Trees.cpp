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
/*****************Optimal Approach to find Maximum Depth of Binary Trees *********************/
/*****************Time Complexity = O(N)*********************************************/ 
/*****************Space Complexity = O(H)*******************************************/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return max(maxDepth(root -> left) ,maxDepth( root -> right) ) + 1;
    }
};