/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/******************************Recurive Optimal Approach to Find Lowest Common Ancestor******************/
/******************************Time Complexity = O(N)********************************************************/
/*******************************Space Complexity = O(H)******************************************************/
class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root -> val;
        int pVal = p -> val;
        int qVal = q -> val;
        if(rootVal > pVal && rootVal > qVal) return lowestCommonAncestor(root -> left , p , q);
        else if(rootVal < pVal && rootVal < qVal) return lowestCommonAncestor(root -> right , p , q);
        else return root;
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