/***********************Optimal Approach for All Nodes with K Distance in Binary Tree**************/
/************************Time Complexity = O(N)***************************************/
/************************Space Complexity = O(N)**************************************/
class Solution {
private:
    void inorder(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL)
            return;
        if (root->right)
            mp[root->right] = root;
        if (root->left)
            mp[root->left] = root;
        inorder(root->left, mp);
        inorder(root->right, mp);
        return;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        vector<int> ans;
        inorder(root, mp);
        int dist = k;
        queue<TreeNode*> que;
        que.push(target);
        map<TreeNode*, bool> visit;
        while (dist--) {
            int sz = que.size();
            while (sz--) {
                TreeNode* top = que.front();
                que.pop();
                if (visit[top])
                    continue;
                visit[top] = true;
                if (top != root &&  !visit[mp[top]])
                    que.push(mp[top]);

                if (top->right && !visit[top -> right])
                    que.push(top->right);
                if (top->left && !visit[top -> left])
                    que.push(top->left);
            }
        }
        while (!que.empty()) {
            TreeNode* top = que.front();
            que.pop();
            ans.push_back(top->val);
        }

        return ans;
    }
};