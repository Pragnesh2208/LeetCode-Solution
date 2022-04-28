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

/***********************Brute Force Approach for Maximum Product of Spillited Bianry Tree*******/
/************************Time Complexity = O(N)*********************************************/
/************************Space Complexity = O(N)********************************************/

class Solution
{
    long long first = 0;

    long long findSum(TreeNode *root, vector<long long> &arr)
    {

        if (root == NULL)
            return 0;

        long long left = findSum(root->left, arr);
        long long right = findSum(root->right, arr);
        first = max(first, max(left, right));
        arr.push_back(first);
        return left + right + root->val;
    }

public:
    int maxProduct(TreeNode *root)
    {
        vector<long long> arr;
        long long totalSum = findSum(root, arr);
        int n = arr.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, arr[i] * (totalSum - arr[i]));

        return ans % (int)(1e9 + 7);
    }
};

/***********************Optimal Approach for Maximum Product of Spillited Binary Tree*******/
/************************Time Complexity = O(N)*********************************************/
/************************Space Complexity = O(1)********************************************/
class Solution
{
    long long ans = 0;
    long long totalSum = 0;

    long long findSum(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        long long sum = root->val + findSum(root->left) + findSum(root->right);
        ans = max(ans, sum * (totalSum - sum));

        return sum;
    }

public:
    int maxProduct(TreeNode *root)
    {

        totalSum = findSum(root);
        findSum(root);

        return ans % (int)(1e9 + 7);
    }
};