/*********************Optimal Solution to Validate Binary Search Tree*****************************/
/*********************Time Complexity = O(N)******************************************************/
/********************Space Complexity = O(N)******************************************************/
class Solution {
public:
    bool dfs(TreeNode* root) {
        stack<TreeNode*> st;
        long long int prev = LONG_MIN;
        while (root != NULL || !st.empty()) {
            while(root != NULL) {
                st.push(root);
                root = root -> left;
            }

            root = st.top();
            st.pop();
            if(root -> val <= prev) return false;
            prev = root -> val;
            root = root -> right;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) { return dfs(root); }
};