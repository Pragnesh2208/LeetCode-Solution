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
/**********************Optimal Approach to Construct a Balance Binary Search Tree***/
/*********************Time complexity = O (N)*******************************************************/
/**********************Space complexity = O (N)*****************************************************/
class Solution {
    private:
    
    void inorder(TreeNode * root , vector<TreeNode *>&arr) {
        if(root == NULL)
            return ;
        inorder(root -> left  , arr);
        arr.push_back(root);
        inorder(root -> right  , arr);
        root -> left = NULL;
        root -> right = NULL;
    }
    private:
    
    TreeNode * constructBST(vector<TreeNode *> &arr , int low , int high) {
        if(low >= high)
            return arr[low];
        int mid = low +(high - low) /2;
        arr[mid] -> left = constructBST(arr , low , mid - 1 );
        
        if(arr[mid] == arr[mid] -> left)
            arr[mid] -> left = NULL;
       
        arr[mid] -> right = constructBST(arr , mid + 1 , high);
        
        if(arr[mid] == arr[mid] -> right)
            arr[mid] -> right = NULL;
        
        return arr[mid];
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<TreeNode *>inorderArr;
        inorder(root , inorderArr);
        return constructBST(inorderArr , 0 , inorderArr.size() - 1);
        
    }
};