/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*********************Optimal Approach for This problem ********/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    private:
    TreeNode * inorder(TreeNode * origin , TreeNode * clon , TreeNode * target) {
        if(origin == NULL)
            return NULL;
        if(origin == target)
            return clon;
        TreeNode * left = inorder(origin -> left , clon -> left , target);
        TreeNode * right = inorder(origin -> right , clon -> right , target);
        return left ? left : right;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return inorder(original , cloned , target);
    }
};