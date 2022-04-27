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

/***********************Optimal Approach for step by step directions from binary tree node to another************/
/************************Time Complexity = O(logN)***************************************************************/
/************************Space Complexity = O(logN)**************************************************************/
class Solution
{
    bool find(TreeNode *root, int &value, string &path)
    {
        if (root->val == value)
            return true;

        if (root->left && find(root->left, value, path))
            path.push_back('L');

        else if (root->right && find(root->right, value, path))
            path.push_back('R');

        return !path.empty();
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {

        string srt, dst;

        find(root, startValue, srt);
        find(root, destValue, dst);

        while (!srt.empty() && !dst.empty() && srt.back() == dst.back())
        {
            srt.pop_back();
            dst.pop_back();
        }
        return string(srt.size(), 'U') + string(rbegin(dst), rend(dst));
    }
};