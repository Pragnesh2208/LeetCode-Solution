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

/***********************Optimal Approach Even Odd Tree*************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(N)**************************************************/

class Solution {
    bool DFS(TreeNode * root) {
        queue<TreeNode *> que;
        bool iseven = false;
        que.push(root);        
        while(!que.empty()) {
            
            int size = que.size();
            int prev;
            if(iseven) prev = INT_MAX;
            else
                prev = 0;
            
            while(size--) {
                TreeNode * node = que.front();
                que.pop();
               
               
                if(iseven &&  node -> val %2 == 0 && node -> val < prev) 
                 prev = node -> val;
                
                else if(!iseven && node -> val %2 == 1 && node -> val > prev)
                        prev = node -> val;
                
                else
                    return false;
                
                 if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
                }
            iseven = !iseven;
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
       return DFS(root);
    }
};