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
/***********************Brute Approach to Check Completeness of Binary Tree**********************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(N)**************************************************/
class Solution {
    bool BFS(TreeNode * root) {
        if(root == NULL)
            return true;
        queue<TreeNode * > que;
        bool isNullseen = false;
        que.push(root);
        while(!que.empty()) {
            TreeNode * node = que.front();
            que.pop();
            if(isNullseen && node != NULL)
                return false;
            if(node  == NULL)
                isNullseen = true;
           else {
                que.push(node -> left);    
                que.push(node -> right);
           }
        }
        
        return true;
    }
public:
    bool isCompleteTree(TreeNode* root) {
     return BFS(root);
        
    }
};

/***********************Optimal Approach to Check Completeness of Binary Tree**********************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(h)**************************************************/

class Solution {
   int dfs(TreeNode * root) {
       if(root == NULL) return 0;
       
       int left = dfs(root -> left);
       int right = dfs(root -> right);
       /*
       if the left Subtree is full then the number of nodes in left subtree would be 2^k - 1 and right subtree would have less nodes than left subtree
       */ 
       if((left & (left + 1)) == 0 && left >=right && left/2 <= right)
           return left + right + 1;
        /*
       if the right Subtree is full then the number of nodes in right subtree would be 2^k - 1 and left subtree would have more nodes than right subtree
       */ 
       if((right & (right + 1) )== 0 && left>=right && left <= 2 * right + 1)
           return left + right + 1;
       
       return -1;
   }
public:
    bool isCompleteTree(TreeNode* root) {
        return dfs(root) >=0;
      
    }
};