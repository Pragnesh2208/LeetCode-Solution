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

/***********************Optimal Approach for Flip Binary Tree to Match Preorder Traversal*********/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(h)**************************************************/

class Solution {
     vector<int> flip ;
     int ind = 0 ;
    
    bool dfs(TreeNode * root , vector<int>&voyage) {
        if(!root) return true;
        if(root -> val != voyage[ind++]) return false;
        if(root -> left && root -> left -> val != voyage[ind]) {
            
            flip.push_back(root -> val);
            return dfs(root -> right , voyage) && dfs(root -> left , voyage);  
        }
        else 
            return dfs(root -> left , voyage ) && dfs(root -> right , voyage);
    }
   
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      
        return dfs(root , voyage ) ? flip : vector<int>{-1};
    }
};