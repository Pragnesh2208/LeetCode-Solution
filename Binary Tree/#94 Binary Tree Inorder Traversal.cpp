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
/*********************Brute Force Recursive Approach to Binary Tree Inorder Traversal*****************************/
/*********************Time Complexity = O(N)*********************************************************************/
/********************Space Complexity = O(H)******************************************************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<int> & ans) {
        if(root == NULL)
            return;
        inorder(root -> left , ans);
        ans.push_back(root -> val);
        inorder(root -> right , ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root , ans);
        return ans;
    }
};

/*********************Optimal Approach to Binary Tree Inorder Traversal using Morris Traversal*******************/
/*********************Time Complexity = O(N)*********************************************************************/
/********************Space Complexity = O(1)*********************************************************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<int> & ans) {
       while(root != NULL) {
            if(root -> left == NULL) {
                ans.push_back(root -> val);
                root = root -> right;
            }
            else {
                TreeNode * pre = root -> left;
                while(pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if(pre -> right == root) {
                    pre -> right = NULL;
                    ans.push_back(root -> val);
                    root = root -> right;
                }
                else {
                    pre -> right = root;
                    root = root -> left;
                }
                
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root , ans);
        return ans;
    }
};