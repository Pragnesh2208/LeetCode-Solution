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
/***********************Recurive Optimal Approach to check if trees are same or not******************/
/************************Time Complexity = O(N)********************************************************/
/************************Space Complexity = O(H)******************************************************/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if( (p != NULL && q == NULL ) || (p == NULL && q != NULL))
            return false;
        bool left , right;
        left = isSameTree(p -> left , q -> left);
        if(p -> val != q -> val) return false;
        right = isSameTree(p -> right , q -> right);
        return (left && right);
    }
};

