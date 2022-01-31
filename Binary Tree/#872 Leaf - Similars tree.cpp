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
/****************************Optimal Approach to Leaf - Similar Tree*********************/
/****************************Time complexity = O(N)**********************************/
/***************************Space Complexity = O(H)**********************************/
class Solution {
    private:
    void dfs(vector<int> & arr , TreeNode * root) {
        if(root == NULL) 
            return;
        dfs(arr , root -> left);
        dfs(arr , root -> right);
        if(!root -> left && !root -> right )
            arr.push_back(root -> val);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1 , tree2;
        dfs(tree1 , root1);
         dfs(tree2 , root2);
        return tree1 == tree2 ;
    }
};