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
/**********************Optimal Approach to Find Maximum Sum in BST****************************/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (H)*****************************************************/
class NodeValue {
    public :
    int maxVal , minVal , sum;
    NodeValue(int minVal , int maxVal , int sum) {
        this -> minVal = minVal;
        this -> maxVal = maxVal;
        this -> sum = sum;
    }
};
class Solution {
    public:
    int ans = 0;
     public:
    NodeValue LargestBST(TreeNode * root) {
        if(root == NULL) 
            return NodeValue(INT_MAX , INT_MIN , 0);
        auto left = LargestBST(root -> left);
        auto right = LargestBST(root -> right);
        if(root -> val > left.maxVal && root -> val < right.minVal) {
                ans = max(ans , left.sum + right.sum + root -> val);
            return NodeValue( min(root -> val , left.minVal),max(root -> val , right.maxVal)  ,left.sum+right.sum + root -> val);
        }
        else {
            return NodeValue(INT_MIN , INT_MAX , max(left.sum , right.sum));
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        LargestBST(root);
        return ans; 
    }
};