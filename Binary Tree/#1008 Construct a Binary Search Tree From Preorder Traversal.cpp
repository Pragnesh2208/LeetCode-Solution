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

/**********************Brute Force Approach to Construct a Binary Search Tree From preorder Traversal****/
/*********************Time complexity = O ( N ^ 2 )******************************************************/
/**********************Space complexity = O (H)**********************************************************/
class Solution {
    private :
    TreeNode * constructTree(vector<int>&pre , int low , int high) {
        if(low > high)
            return NULL;
        if(low == high)
            return new TreeNode(pre[low]);
      
        TreeNode * root = new TreeNode(pre[low]);
          int ind = findRoot(pre , low  ,high);
        root -> left = constructTree(pre , low  + 1, ind - 1);
        root -> right = constructTree(pre , ind , high);
        return root;
    }
   int findRoot(vector<int>&pre , int low , int high) {
       int Max = INT_MIN , ind;
       for(int i = low ; i <= high ; i++)
          if(pre[i]>pre[low]) {
              ind = i;
              break;}
       return ind;
   }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       return constructTree(preorder , 0 , preorder.size() - 1);
        
    }
};
/**********************Optimal Approach to Construct a Binary Search Tree From preorder Traversal***/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class Solution {
    private :
       int idx = 0;
    public: 
TreeNode* bstFromPreorder(vector<int>& preorder, int p_val = INT_MAX) {
    if (idx >= preorder.size() || preorder[idx] > p_val)
        return nullptr;
    auto n = new TreeNode(preorder[idx++]);
    n->left = bstFromPreorder(preorder, n->val);
    n->right = bstFromPreorder(preorder, p_val);
    return n;
}
};