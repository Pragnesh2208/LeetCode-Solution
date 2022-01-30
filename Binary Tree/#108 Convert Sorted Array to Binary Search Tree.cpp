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
/**************Optimal approach to Convert sorted array to binary search tree*****************/
/**************Time Complexity = O(n)********************************************************/
/**************Space Complexity = O(H)*******************************************************/
class Solution {
    private:
    TreeNode * helper(int low , int high , vector<int>&nums) {
        if(low > high) 
            return NULL;
        int mid = low + (high - low )/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root -> left = helper(low , mid - 1 , nums);
        root -> right = helper(mid + 1 , high , nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return helper( 0 , nums.size() - 1, nums);
    }
};