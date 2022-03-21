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

/*********************Brute Force Recusrion Approach for Flatten Binary Tree to Linked List********/
/*********************Time complexity = O (N)******************************************************/
/**********************Space complexity = O (N )***************************************************/
class Solution {
    private:
    TreeNode * prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        flatten(root -> right);
        flatten(root -> left);
        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
};

/*********************Brute Force Approach Using Stack for Flatten Binary Tree to Linked List********/
/*********************Time complexity = O (N)******************************************************/
/**********************Space complexity = O (N )***************************************************/
class Solution {
    private:
    
public:
    void flatten(TreeNode* root) {
   if(root == NULL)
       return;
        stack<TreeNode *>st;
        st.push(root);
        
        while(!st.empty() ) {
            TreeNode *node = st.top();
            st.pop();
            
            if(node -> right)
                st.push(node -> right);
            
            if(node -> left )
                st.push(node -> left);
            
            if(!st.empty())
                node -> right = st.top();
           
            node -> left = NULL;
            
        }
    } 
};

/*********************Optimal Approach for Flatten Binary Tree to Linked List***********/
/*********************Time complexity = O (N)*******************************************/
/**********************Space complexity = O (1 )****************************************/
class Solution {
    private:
    
public:
    void flatten(TreeNode* root) {
   if(root == NULL)
       return;
        TreeNode * cur = root;
        while(cur) {
            
            if(cur -> left) {
                
                TreeNode *node = cur -> left;
                
                while(node -> right ) 
                    node = node -> right;
                node -> right = cur -> right;
                
                cur -> right = cur -> left;
                cur ->left = NULL;
            }
            cur = cur -> right;
        }
    } 
};
    