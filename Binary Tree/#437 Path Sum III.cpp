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

/***********************Brute Force Approach to Path Sum III*********************/
/************************Time Complexity = O(N ^ 2)****************************************/
/************************Space Complexity = O(h)***************************************/
class Solution
{
    int path(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return 0;
        int count = 0;
        if (root->val == sum)
            count = 1;
        int newSum = sum - root->val;
        return path(root->left, newSum) + path(root->right, newSum) + count;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + path(root, targetSum);
    }
};

/***********************Optimal Approach to Path Sum III*********************/
/************************Time Complexity = O(N )****************************************/
/************************Space Complexity = O(N)***************************************/
class Solution
{
public:
    int path(TreeNode *root, int currentSum, int targetSum, unordered_map<int, int> &map)
    {
        if (root == NULL)
            return 0;
        currentSum += root->val;
        int count = map[currentSum - targetSum];
        map[currentSum]++;
        count += path(root->left, currentSum, targetSum, map);
        count += path(root->right, currentSum, targetSum, map);
        map[currentSum]--;
        currentSum -= root->val;
        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        unordered_map<int, int> map;
        map[0] = 1;
        return path(root, 0, targetSum, map);
    }
};
