/*********************Better Approach for Construct a Binary Tree From Inorder and PretOrder Traversal***************/
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