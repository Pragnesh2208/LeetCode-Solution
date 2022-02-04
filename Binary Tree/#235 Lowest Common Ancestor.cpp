/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/******************************Recurive Brute Force Approach to Find Lowest Common Ancestor******************/
/******************************Time Complexity = O(N)********************************************************/
/*******************************Space Complexity = O(H)******************************************************/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        if(root == p || root == q) 
            return root;
        TreeNode * left = lowestCommonAncestor(root -> left , p,  q);
        TreeNode * right = lowestCommonAncestor(root -> right , p,  q);
        if(left && right)
            return root;
        return left?left : right;
    }
};
/******************************Optimal Force Approach to Find Lowest Common Ancestor******************/
/******************************Time Complexity = O(N)********************************************************/
/*******************************Space Complexity = O(1)******************************************************/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val) {
                cur = cur -> left;
            } else if (p -> val > cur -> val && q -> val > cur -> val) {
                cur = cur -> right;
            } else {
                break;
            }
        }
        return cur;
         
    }
};