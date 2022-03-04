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
/*********************Level Order Traversal in Bianry Tree**************************/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (N )************************************/
class Solution {
    private:
    void bfs(TreeNode* root , unordered_map<int ,vector<int>>&map ) {
        if(root==NULL)
            return;
        int level =0;
        queue<TreeNode *>que;
        que.push(root);
        while(!que.empty()) {
           
            int size = que.size();
            while(size--) {
                 TreeNode * node = que.front();
                que.pop();
                if(node -> left)
                    que.push(node -> left);
                if(node -> right)
                    que.push(node -> right);
                map[level].push_back(node -> val);
                cout<<node -> val<<" ";
            }
            level++;
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int , vector<int>>map;
        bfs(root , map );
        vector<vector<int > >ans(map.size()) ;
        for(int i = 0 ; i < map.size() ; i++) 
            for(int j = 0 ; j < map[i].size() ;j++) {
                 ans[i].push_back(map[i][j]);
                //cout<<j<<" "; 
            }
        
        return ans;
    }
};