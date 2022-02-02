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
/**************************Optimal Approach for Binary Tree Path*******************************************/
/**************************Time Complexity = O(N)************************************************************/
/*************************Space Complexity = O(H)************************************************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<string> & ans , string temp) {
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(temp);
        }
        if ( root -> left)
        inorder(root -> left , ans ,temp  + "->" +to_string(  root -> left -> val));
        if ( root -> right)
        inorder(root -> right , ans , temp + "->" +to_string(root -> right -> val));
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        inorder(root , ans , to_string(root -> val));
        return ans;
    }
};