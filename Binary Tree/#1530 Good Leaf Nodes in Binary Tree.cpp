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
/*********************Optimal Approach for Good Leaf Nodes in Binary Tree***********/
/*********************Time complexity = O (N * (Number of Leaf ^ 2))***************************************/
/**********************Space complexity = O (N + Number of Leaf)************************************/
class Solution {
    int count = 0 ;
    private:
    vector<int> dfs(TreeNode * root , int &dist ) {
        if(root == NULL)
            return {};
        
        vector<int> l= dfs(root -> left , dist);
        vector<int> r = dfs(root -> right ,dist );
        
        if(root -> left == NULL && root -> right == NULL )
            return {1};
        
         vector<int>p;
        
        for(int i = 0 ; i < l.size() ; i++)
            for(int j = 0 ; j < r.size() ; j++)
                if(l[i]+r[j]<=dist)
                    count++;
       
        for(int j = 0  ; j < l.size() ; j++){
            l[j]++;
            p.push_back(l[j]);
        }
        for(int i = 0 ; i < r.size() ; i++){
            r[i]++;
            p.push_back(r[i]);
        }
        
        return p;
       
    }
public:
    int countPairs(TreeNode* root, int distance) {
       dfs(root , distance);
       
        return count;
    }
};