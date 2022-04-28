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

/***********************Optimal Approach for Verify Preorder Traversal of Binary Tree*******/
/************************Time Complexity = O(N)*********************************************/
/************************Space Complexity = O(1)********************************************/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        
     if(preorder.empty() ) return false;
     preorder +=',';
        int capacity = 1;
        for(int i = 0 ; i < preorder.size() ; i++) {
            if(preorder[i] !=',') continue;
            capacity--;
            if(capacity < 0) return false;
            if(preorder[i - 1] !='#') capacity +=2;
            
        }
        return capacity == 0;
    }
};