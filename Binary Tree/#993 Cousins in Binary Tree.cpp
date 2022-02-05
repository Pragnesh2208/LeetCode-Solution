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
/***********************Recurive Optimal Approach For Cousins in Binary Tree******************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(H)**************************************************/
class Solution {
    private:
    int parent1 = -1 , parent2 = -1 , height1 = -1 , height2 = -1;
    private :
    void inorder(TreeNode * root , int x , int y  , int height) {
     
       if( (root -> left&& root -> left -> val == x ) || (root -> right && root -> right -> val == x ) ){
           parent1 = root -> val;
           height1 = height;
       }
        else if((root -> left&& root -> left -> val == y ) || (root -> right && root -> right -> val == y )){
           parent2 = root -> val;
           height2 = height;
       }
        if( root -> left ) inorder(root -> left , x , y , height + 1);
        if(root -> right) inorder(root -> right , x , y , height + 1);
        return;
    }
    private:
    bool check() {
        return (parent1 != parent2 && height1 == height2);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
            inorder(root , x , y , 0);
            return check();
    }
};