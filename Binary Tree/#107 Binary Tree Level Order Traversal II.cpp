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
/*********************Optimal Approach for Binary Tree Level Order Traversal II***********/
/*********************Time complexity = O (N )***************************************/
/**********************Space complexity = O (N )************************************/
class Solution
{
    class Solution
    {
        void bfs(TreeNode *root, vector<vector<int>> &map)
        {
            if (root == NULL)
                return;
            queue<TreeNode *> que;
            que.push(root);

            while (!que.empty())
            {
                int size = que.size();
                vector<int> arr;
                while (size--)
                {
                    TreeNode *node = que.front();
                    que.pop();
                    if (node->left)
                        que.push(node->left);
                    if (node->right)
                        que.push(node->right);
                    arr.push_back(node->val);
                }
                map.push_back(arr);
            }
        }

        void reverse(vector<vector<int>> &arr)
        {

            int low = 0, high = arr.size() - 1;
            while (low < high)
            {
                swap(arr[low], arr[high]);
                low++;
                high--;
            }
        }

    public:
        vector<vector<int>> levelOrderBottom(TreeNode *root)
        {
            if (!root)
                return root;
            vector<vector<int>> ans;
            bfs(root, ans);

            reverse(ans);
            return ans;
        }
    };