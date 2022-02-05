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
/***********************Recurive Optimal Approach For Symmetric Tree******************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    private:
    bool inorder(TreeNode * r1 , TreeNode * r2) {
       if(r1 == NULL && r2 == NULL)
           return true;
        if( (r1 == NULL && r2 != NULL ) ||(r2 == NULL && r1 != NULL ) )
            return false;
       bool left = false , right = false;
        if(!r1  && !r2)
            return false;
        
        
        left = inorder(r1 -> left , r2 -> right);
        if(r1 -> val != r2 -> val)
            return false;
        
            if(!r1  && !r2)
            return false;
        
        right =  inorder(r1 -> right , r2 -> left);
        return (left && right);
    }
public:
    bool isSymmetric(TreeNode* root) {
     return inorder(root -> left , root -> right); 
    }
};