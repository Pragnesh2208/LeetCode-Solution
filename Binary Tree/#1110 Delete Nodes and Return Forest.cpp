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
/**********************Optimal Approach for Delete Nodes And Return Forest*************/
/*********************Time complexity = O (N)******************************************/
/**********************Space complexity = O (H) + O(to_delete_Node)********************/
class Solution {
    public:
     vector<TreeNode*> res;
    set<int> dp;
    
    TreeNode * util (TreeNode* &root)
    {
        if(root!=NULL)
        {
            util(root->left);
            util(root->right);
            if(dp.find(root->val)!=dp.end())
            {
                if(root->left)  res.push_back(root->left);
                if(root->right) res.push_back(root->right);
                root=NULL;
				delete root;
                return NULL;
            }
            
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
	
        for(int i=0;i<to_delete.size();i++)
            dp.insert(to_delete[i]);
        util(root);
        if(root)
            res.push_back(root);
        return res;
    }
};