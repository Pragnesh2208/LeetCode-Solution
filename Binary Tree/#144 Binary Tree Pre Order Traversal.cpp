/**************************Recursive Brute Force Approach for Inorder Binary Tree Traversal*****************/
/**************************Time Complexity = O(N)************************************************************/
/*************************Space Complexity = O(H)************************************************************/
class Solution {
    private :
    void preorder(TreeNode * root , vector<int> & arr) {
        if(root == NULL)
            return;
          arr.push_back(root -> val);
        preorder(root -> left , arr);
        preorder(root -> right , arr);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root , ans);
        return ans;
    }
};
/**************************Optimal Approach for Inorder Binary Tree Traversal using Morris Traversal*********/
/**************************Time Complexity = O(N)************************************************************/
/*************************Space Complexity = O(1)************************************************************/
class Solution {
    private :
    void preorder(TreeNode * root , vector<int> & arr) {
        
        while(root != NULL) {
           
            if(root -> left == NULL) {
                 arr.push_back(root -> val);
                root = root -> right;
                
            }
            else {
                TreeNode * pre = root -> left;
                while(pre -> right != NULL && pre -> right != root) 
                    pre = pre -> right;
                
                if(pre -> right == root) {
                    
                    root = root -> right;
                    pre -> right = NULL;
                }
                else {
                    
                    pre -> right = root;
                     arr.push_back(root -> val);
                    root = root -> left;
                   
                }
            }
        }
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root , ans);
        return ans;
    }
};