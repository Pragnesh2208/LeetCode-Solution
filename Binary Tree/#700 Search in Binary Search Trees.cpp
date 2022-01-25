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
/***************************Brute Force Approach to Search in Binary Search Trees********************/
/***************************Time complexity = O (N) *************************************/
/***************************Space Complexity = O (H) ************************************/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if(root == NULL)
            return NULL;
        if(root -> val == val)
            return root;

        TreeNode * ans = searchBST(root -> left , val);

        if(ans == NULL)
        ans = searchBST(root -> right , val);
        
        return ans;
    }
};
/***************************Optimal Approach to Search in Binary Search Trees********************/
/***************************Time complexity = O (LOGN) *************************************/
/***************************Space Complexity = O (H) ************************************/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        if(root -> val == val)
            return root;
        
        TreeNode * ans;
        if( root -> val > val)
        ans = searchBST(root -> left , val);
        
        else
        ans = searchBST(root -> right , val);
        
        return ans;

    }
};