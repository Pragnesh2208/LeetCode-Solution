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
/*Note :
We can Construct a full unique binary tree using preorder and postorder traversal*/ 
/**********************Optimal Approach for Construct a Binary Tree From preorder and PostOrder Traversal*************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {

    int preIndex = 0 , postIndex = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode * root = new TreeNode(pre[preIndex++]);
        
        if(root -> val != post[postIndex])
            root -> left = constructFromPrePost(pre , post);
        
        if(root -> val != post[postIndex])
            root -> right = constructFromPrePost(pre , post);
        
        postIndex++;
        return root;
    }
};