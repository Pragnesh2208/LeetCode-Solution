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
/***************************Recursive Post Order Traversal*****************/
/**************************Time Complexity = O(N)*************************/
/************************Space Complexity = O(N)*************************/
class Solution {
    private:
    void postorder(TreeNode  * root , vector<int>&arr) {
        if(!root)
            return;
        postorder(root -> left , arr);
        postorder(root -> right , arr);
        arr.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root , ans);
        return ans;
        
    }
};

/***************************Iterative Post Order Traversal*****************/
/**************************Time Complexity = O(N)*************************/
/************************Space Complexity = O(N)*************************/
class Solution {
    private:
    void postorder(TreeNode  * root , vector<int>&arr) {
        stack<TreeNode  * > st;
        if(root == NULL)
            return;
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root = root -> left;
            }
            else {
                TreeNode * temp = st.top() -> right;
                if(!temp) {
                    temp = st.top();
                st.pop();
                    arr.push_back(temp -> val);
                while(!st.empty() && st.top() -> right== temp) {
                   
                  
                     temp = st.top();
                    st.pop();
                      arr.push_back(temp -> val);
                }
                }
                else
                    root = temp;
                
            }
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root , ans);
        return ans;
        
    }
};