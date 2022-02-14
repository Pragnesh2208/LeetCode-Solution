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
/**********************Brute Force Approach For Maximum Binary Tree*********/
/*********************Time complexity = O (N ^ 2)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    TreeNode * constructTree(vector<int>&nums ,  int  low , int high) {
        if(high < low)
            return NULL;
        if(high == low)
            return new TreeNode(nums[low]);
        int rootVal = findMax(nums , low , high);
        TreeNode * root = new TreeNode(nums[rootVal]);
        root -> left = constructTree(nums , low , rootVal - 1);
        root -> right = constructTree(nums , rootVal + 1 , high);
        return root;
        }
    int findMax (vector<int>&nums , int &low ,int &high) {
        int Max = INT_MIN;
        int ind;
        for(int i = low ; i <= high ; i++) {
           if(Max < nums[i]) {
               ind  = i;
               Max = max(Max , nums[i]);
           }
        }
           
        return ind;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums , 0 , nums.size() - 1);
    }
};

/**********************Optimal Approach For Maximum Binary Tree Using Stack*********/
/*********************Time complexity = O (N )***************************************/
/**********************Space complexity = O (N)*************************************/
class Solution {
  
public:
     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;
         int n = nums.size();
         for(int i = 0 ; i < n ; i++) {
             TreeNode * cur = new TreeNode(nums[i]);
             while(!st.empty() && st.top() -> val < nums[i]) {
                 cur -> left = st.top();
                 st.pop();
             }
             if(!st.empty())
                 st.top() -> right = cur;
             st.push(cur);
         }
         while(st.size() > 1)
             st.pop();
         return st.top();
         
      
    }
};