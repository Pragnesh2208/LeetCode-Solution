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


/***********************Brute Force Approach for Recover Bianry Search Tree using Inorder Traversal************/
/************************Time Complexity = O(N)****************************************/
/************************Space Complexity = O(H)***************************************/
class Solution {
    TreeNode * first = NULL , *second = NULL;
    TreeNode * middle = NULL;
    TreeNode * prev = NULL;
    private:
    int ind = 0;
    void dfs(TreeNode * root , vector<int>&arr) {
        
        if(root == NULL) return;
        
        dfs(root -> left ,arr);
        if(prev != NULL && root -> val < prev ->val)  {
           if(!first) {first = prev;
                      middle = root;
                      }
            else
                second  = root;
        }
        prev  = root ;
        dfs(root -> right , arr);
    
    }
   
public:
    void recoverTree(TreeNode* root) {
        vector<int>arr;
        dfs(root  , arr);
        if(first && second)
            swap(first -> val , second -> val);
        else if( first && middle)
            swap(first -> val , middle -> val);

            
       
        
    }
};

/***********************Optimal Approach for Recover Bianry Search Tree using Inorder Traversal************/
/************************Time Complexity = O(N)****************************************/
/************************Space Complexity = O(1)***************************************/
class Solution {
    TreeNode * first = NULL , *second = NULL;
    TreeNode * middle = NULL;
    TreeNode * prev = NULL;
    private:
    int ind = 0;
    void morrision_traversal(TreeNode * root , vector<int>&arr) {
    
        if(root == NULL) return;
        
       while(root) {
           if(!root -> left) {
               
            if(prev != NULL && prev -> val != root ->val && root -> val < prev ->val)  {
                 if(!first) {
                     first = prev;
                      middle = root;
                    }
            else second  = root;
                }
               prev  = root ;
               root = root -> right;   
           }
           else {
               TreeNode * proc = root -> left;
               
               while(proc -> right && proc ->right != root)
                   proc = proc -> right;
               
               if(proc -> right  == root) {
                   proc -> right =NULL;
                    if(prev != NULL && prev -> val != root ->val && root -> val < prev ->val)  {
                       if(!first) {
                           first = prev;
                           middle = root;
                            }
                        else
                            second  = root;
                                }
                               prev  = root ;
                               root = root -> right;
                           }
                           else{
                   proc -> right = root;
                   root = root -> left;
                   
          
                }
            }
       }
    }
   
public:
    void recoverTree(TreeNode* root) {
        vector<int>arr;
        morrision_traversal(root  , arr);
        if(first && second)
            swap(first -> val , second -> val);
        else if( first && middle)
            swap(first -> val , middle -> val);
        
    }
};