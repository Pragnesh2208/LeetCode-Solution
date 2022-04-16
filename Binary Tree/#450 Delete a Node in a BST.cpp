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
/***********************Optimal Approach Delete a Node in a BST*********************/
/************************Time Complexity = O(N)****************************************/
/************************Space Complexity = O(h)***************************************/
class Solution {
    TreeNode * dfs(TreeNode *root , int &key ) {
        if(root == NULL) return NULL;
        if(root -> val == key) return helper(root);
        if(key > root -> val) 
            root -> right = dfs(root -> right , key);
        else 
            root -> left = dfs(root -> left , key);
        
       return root;
    }
    TreeNode * helper(TreeNode * root) {
        TreeNode * cur = root;
    if(root -> left == NULL) {
        cur = root -> right;
        delete(root);
        return cur;
    }
        else if(root -> right == NULL ) {
            cur = root -> left;
        delete(root);
        return cur;
        }
        else {
        TreeNode * ans = root -> left;
        TreeNode * mostRight = ans ;
        while(mostRight -> right !=NULL) mostRight = mostRight -> right;
        mostRight -> right = root -> right;
        delete(root);
        return ans; 
        }
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root == NULL)
           return NULL;
       return dfs(root , key);
      
            
        }
    
};