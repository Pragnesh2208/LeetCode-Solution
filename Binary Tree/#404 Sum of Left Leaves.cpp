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
/***********************Recurive Brute Force Approach to Find Sum of Left Leaves******************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    private:
    void inorder(TreeNode * root , int &sum){
        if(root == NULL)
            return;
        
        inorder(root -> left, sum); 
        if(root -> left && root -> left -> left == NULL && root ->left -> right == NULL)
            sum += root -> left -> val;
        inorder(root -> right , sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        inorder(root , sum);
        return sum;
    }
};

/***********************Optimal Approach to Find Sum of Left Leaves*******************************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(1)**************************************************/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        while(root) {
           if(root -> left == NULL)  root = root -> right;
           else{
                TreeNode * pre = root -> left;
                while(pre -> right && pre ->right != root) 
                    pre = pre -> right;
                if(pre -> right == root){
                    pre -> right = NULL;
                    
                    if(root -> left == pre && pre -> left == NULL)
                    ans += pre -> val;
                    root = root -> right;
                }
                else{
                    pre -> right = root;
                    root = root -> left;
                }
            }
        }
        return ans;
    }
};