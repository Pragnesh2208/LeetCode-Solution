/**********************Optimal Approach to get Range sum of BST*****************************/
/**********************Time Complexity = O(N)***********************************************/
/**********************Space Complexity = O(N)**********************************************/
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
class Solution {
    int ans = 0;
    private:
    void inorder(TreeNode * root , int &low ,int &high){
        if(root == NULL) return;
        else if(root -> val <= high && root ->val >= low){
            ans += root ->val;
        }
        inorder(root -> left , low , high);
        inorder(root -> right , low , high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root , low , high);
        return ans;
    }
};