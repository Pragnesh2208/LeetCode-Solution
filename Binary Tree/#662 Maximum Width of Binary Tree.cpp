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

/***********************Optimal Approach for Maximum Width of Binary Tree*******/
/************************Time Complexity = O(N)*********************************/
/************************Space Complexity = O(N)********************************/
class Solution {
    long long ans = 0;

    int bfs(TreeNode * root , int number) {
        
        if(root == NULL) return number - 1;
       queue<pair<TreeNode * , long long > > que;
        
        que.push(make_pair(root , 0));

        while(!que.empty()) {

            int sz = que.size();
            int Min = que.front().second;
            int first , last;

            for(int i = 0 ; i < sz ; i++) {

                TreeNode * node =  que.front().first;
                long long Index = que.front().second - Min;

                if(i == 0) first = Index;
                if(i == sz - 1) last = Index;
                que.pop();
                
                if(node -> left)
                    que.push(make_pair(node -> left , (Index + 1) * 2 + 1 )  );
                if(node -> right)
                    que.push(make_pair(node -> right , (Index + 1) * 2 + 2 )  );
            } 
            long long temp = last - first + 1;
            ans = max(ans ,temp );
        }
        return ans;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
         bfs(root , 0);
        return (int)ans;
    }
};