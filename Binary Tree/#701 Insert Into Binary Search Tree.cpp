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
/**********************Optimal Approach to Insert Into Binary Search Tree****************************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (1)*****************************************************/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * Node = new TreeNode(val);
        if(root == NULL)
            return Node;
        TreeNode * cur = root;
        while(true) {
            if(cur -> val < val) {
                if(cur -> right)
                    cur = cur -> right;
                else {
                    cur -> right = Node;
                    break;
                }
            } 
            else {
                if(cur -> left)
                    cur = cur -> left;
                else {
                    cur -> left = Node;
                    break;
                }
            }    
        }
        return root;
    }
};