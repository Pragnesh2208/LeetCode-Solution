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
public:
    TreeNode * cs(vector<int>&pr , map<int,int>&mp, int &ri , int low , int high) {
        
        if(low > high) return NULL;
        TreeNode * root = new TreeNode(pr[ri]);
        int pivot = mp[pr[ri]];
        ri++;
        root -> left = cs(pr , mp , ri  , low , pivot - 1);
        root -> right = cs(pr , mp , ri  , pivot + 1 , high);

        return root;
    }
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        int rootIndex = 0;
        map<int,int>mp;
        for(int i = 0; i < in.size() ; i++) mp[in[i]] = i;
        return cs(pr , mp , rootIndex , 0 , in.size() - 1);
    }
};