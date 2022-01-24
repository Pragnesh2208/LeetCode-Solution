/**********************Optimal Approach to get Increasing order search tree******************/
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
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy= new TreeNode(0);
        TreeNode *ans = dummy;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode * node = st.top();
            if(node -> left != NULL)
            {
                st.push(node->left); 
                node->left = NULL;
              
            }
            else {
               dummy -> right = st.top();
               TreeNode * node = st.top();
                st.pop();
                if(node -> right != NULL)
                    st.push(n-> right);
                node ->left = NULL;
                node ->right = NULL;
                dummy = dummy -> right;
            }
        }
        return ans -> right;
    }
};