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
/**************************Brute Force Recursive Approach for Binary Tree Path*******************************************/
/**************************Time Complexity = O(N)************************************************************/
/*************************Space Complexity = O(H)************************************************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<string> & ans , string temp) {
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(temp);
        }
        if ( root -> left)
        inorder(root -> left , ans ,temp  + "->" +to_string(  root -> left -> val));
        if ( root -> right)
        inorder(root -> right , ans , temp + "->" +to_string(root -> right -> val));
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        inorder(root , ans , to_string(root -> val));
        return ans;
    }
};
/**************************Optimal Approach for Binary Tree Path using Morris Traversal*******************************************/
/**************************Time Complexity = O(N)************************************************************/
/*************************Space Complexity = O(1)************************************************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<string> & ans) {
        string temp=" " ;
      cout<<temp.size() <<endl;
       while(root != NULL) {
           
            if(root -> left == NULL) {
                temp +=  "->" + to_string(root -> val);
                if(root -> right == NULL) {
                    string t ;
                    t.append(temp.begin() + 3  , temp.end()); 
                     ans.push_back(t);
                }
                   
                root = root -> right;
            }
            else {
                TreeNode * pre = root -> left;
                int step = 1;
                while(pre -> right && pre -> right != root) 
                    {
                        pre = pre -> right;
                        step++;
                    }
                if(pre -> right == root) {
                    pre -> right = NULL;
                    if(pre -> left == NULL) {  
                        string t ;
                        t.append(temp.begin() + 3  , temp.end()); 
                        ans.push_back(t);        
                    }  
                       for(int i = 0 ; i < step ; i++) {
                        temp.pop_back();
                        temp.pop_back();
                        temp.pop_back();
                    }
                    root = root -> right;
                }
                else {
                    pre -> right = root;
                    temp += "->" + to_string(root -> val);
                    root = root -> left;
                }  
            }
        }
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        inorder(root , ans );
        return ans;
    }
};
