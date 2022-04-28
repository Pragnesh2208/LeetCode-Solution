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
/************************Using HashMap*******************************************************/
/***********************Optimal Approach for Maximum Product of Spillited Bianry Tree*******/
/************************Time Complexity = O(N)*********************************************/
/************************Space Complexity = O(N)********************************************/
class Solution {
    int findSum(TreeNode * root , unordered_map<TreeNode *  , int >&arr) {
        if(root == NULL) return 0;
        
        int left = findSum(root -> left , arr);
        int right = findSum (root -> right , arr);
        
        arr[root] = (left + right + root -> val);
        
        return left + right + root -> val;
    }
    void findMax(TreeNode * root , long long &totalSum , unordered_map<TreeNode * , int >&sum , long long &ans) {
        if(root == NULL) return;
        findMax(root -> left , totalSum , sum , ans);
         ans = max(ans , (totalSum - sum[root])* sum[root] ) ;
       
        findMax(root -> right , totalSum , sum , ans);
    }
public:
    int maxProduct(TreeNode* root) {

        unordered_map<TreeNode * , int> sum;
        long long totalSum  = findSum(root , sum);
        long long ans = 0;
       
      
       findMax(root , totalSum , sum , ans);
        return ans % (int)(1e9 + 7);
    }
};

/***********************Without HashMap*****************************************************/
/***********************Optimal Approach for Maximum Product of Spillited Bianry Tree*******/
/************************Time Complexity = O(N)*********************************************/
/************************Space Complexity = O(N)********************************************/

class Solution {
    long long first  = 0 ;
    
    long long  findSum(TreeNode * root , vector<long long> &arr) {
        
        if(root == NULL) return 0;
        
        long long left = findSum(root -> left , arr );
        long long right = findSum (root -> right , arr);
        first = max(first , max(left , right));
        arr.push_back(first);
        return left + right + root -> val;
    }
    
public:
    int maxProduct(TreeNode* root) {
        vector<long long>arr;
        long long totalSum  = findSum(root ,arr);
        int n = arr.size();
         long long ans = 0;
        for(int i = 0 ; i < n;i++)  ans = max(ans , arr[i] * (totalSum - arr[i]));
        
        return ans % (int)(1e9 + 7);
    }
};