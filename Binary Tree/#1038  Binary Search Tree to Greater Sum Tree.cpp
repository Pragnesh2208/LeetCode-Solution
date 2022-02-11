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
/**********************Approach Using 2 Inoreder Traversal for This problem*********/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    private :
    void Gst (TreeNode * root , int &sum) {
        if(root == NULL)
            return;
        Gst(root -> left , sum);
        int temp = root -> val;
        root -> val = sum;
        sum -= temp;
        Gst(root -> right , sum);
    }
    private:
    void inorder(TreeNode * root , int &sum) {
        if(root == NULL)
            return ;
        inorder(root -> left ,sum);
        sum += root -> val;
        inorder(root -> right , sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum =0;
        inorder(root , sum);
        Gst(root , sum);
        return root;
    }
};
/**********************Approach Using 1 Inoreder Traversal for This problem*********/
/*********************Time complexity = O (N)***************************************/
/**********************Space complexity = O (H)*************************************/
class Solution {
    private :
    void Gst (TreeNode * root  , int &pre) {
       if(root -> right != NULL)
           Gst(root -> right ,pre);
        root -> val += pre ;
        pre = root -> val;;     
        if(root -> left)
            Gst(root -> left , pre);
    }
   
public:
    TreeNode* bstToGst(TreeNode* root) {
      int temp = 0;
        Gst(root , temp);
        return root;
    }
};