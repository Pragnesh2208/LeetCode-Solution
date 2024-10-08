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
/*********************Better Approach for Construct a Binary Tree From Inorder and PostOrder Traversal***************/
/*********************Time complexity = O (N * N)*************************************************************************/
/**********************Space complexity = O (H)**********************************************************************/

class Solution {
    TreeNode * Build(vector<int>&in , vector<int>&po , int &Ind  , int low , int high) {
        if(low > high)
            return NULL;
        int pivot =low;
        while( pivot <= high  && in[pivot] != po[Ind]) {
            pivot++;
        }
        
        TreeNode * root = new TreeNode (po[Ind--]);
        
        
        root -> right = Build(in , po , Ind   , pivot + 1 , high);
        root -> left = Build(in , po  , Ind, low , pivot - 1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = inorder.size() - 1;
      return  Build(inorder , postorder ,ind  , 0 , inorder.size() - 1);
    }
};

/*********************Better Approach for Construct a Binary Tree From Inorder and PostOrder Traversal***************/
/*********************Time complexity = O (N * LogN)*************************************************************************/
/**********************Space complexity = O (H + N)**********************************************************************/
class Solution {
    private:
    TreeNode * constructTree(vector<int>&postorder , map<int,int>&mp , int &rootIndex , int low , int high) {
        if(low > high) return NULL;
        int rootElement =  postorder[rootIndex];
        TreeNode * root = new TreeNode(rootElement);
        int pivot = mp[rootElement];
        rootIndex--;
        root -> right = constructTree(postorder , mp , rootIndex , pivot + 1 , high);
        root -> left = constructTree(postorder , mp , rootIndex , low , pivot - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int , int>mp;
        int n = inorder.size() - 1;
        for(int i = 0 ; i <= n ; i++) {
            mp[inorder[i]] = i;
        }
        return constructTree(postorder , mp , n , 0 , n);
    }
};
