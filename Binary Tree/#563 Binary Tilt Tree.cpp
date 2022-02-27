/**************************Optimal Approach for Binary Tilt Tree*******************************************/
/**************************Time Complexity = O(N)************************************************************/
/*************************Space Complexity = O(H)************************************************************/
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
/***********************Optimal Approach For Binary Tilt Tree******************************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/

class Solution {
    int Sum(TreeNode * root , int &sum) {
        if(root == NULL)
            return 0;
      int  left = Sum(root -> left , sum);
      int right = Sum(root -> right , sum);
        sum +=abs(left - right);
        return (left + right+ root -> val);
    }
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        int x = Sum(root , sum);
        return sum;
    }
};