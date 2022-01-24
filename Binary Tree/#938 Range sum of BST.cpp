/**********************Optimal Approach to get Range sum of BST*****************************/
/**********************Time Complexity = O(N)***********************************************/
/**********************Space Complexity = O(N)**********************************************/
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
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> que;
        int sum = 0;
        if(root == nullptr)
            return 0;
        que.push(root);
        while(!que.empty()) {
            TreeNode *top = que.front();
            que.pop();
           
            if(top -> val <= high && top -> val >= low )
            { sum += top -> val;
             if(top -> left != NULL)
            que.push(top -> left);
             if(top -> right != NULL)
            que.push(top -> right);
            }
            if(top -> val < low && top -> right != NULL)
                que.push(top -> right);
            else if(top -> val  > high && top -> left != NULL)
                que.push(top -> left);   
        }
        return sum;
    }
};