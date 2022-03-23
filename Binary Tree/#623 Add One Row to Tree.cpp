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
/**********************************Optimal Approach for Add one Row to Tree*******/
/*********************************Time Complexity = O(N)***************************/
/*********************************Space Complexity = O(N)**************************/
class Solution {
    void get_height_root(TreeNode * root , int depth , vector<TreeNode * > & nodes) {
        
        if(root == NULL )
            return ;
         get_height_root(root ->left , depth - 1 , nodes);
        if(depth ==0)
            nodes.push_back(root);
         get_height_root(root -> right , depth  -1 , nodes);
        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
         
        if(depth == 1) {
           TreeNode * new_root = new TreeNode (val);
            new_root -> left = root;
            return new_root;
        }
        vector<TreeNode * >nodes;
        
        get_height_root(root , depth - 2 , nodes);
        
        for(int i = 0 ; i < nodes.size() ; i++) {
            TreeNode * new_root_left = new TreeNode (val);
            TreeNode * new_root_right = new TreeNode (val);
    
            TreeNode * temp_left = nodes[i] -> left;
            TreeNode * temp_right = nodes[i] -> right;
            nodes[i] -> left = new_root_left;
            nodes[i] -> right = new_root_right;
            
            new_root_left -> left = temp_left;
            new_root_right-> right = temp_right;
            
            
            
        }
        return root;
        
   
    }
};