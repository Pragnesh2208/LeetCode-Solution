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
/***************Method - 1 *******************************************/
/***************Recursive DFS approach********************************/
/***************Approach to Merge Two Binary Trees********************/
/***************Time Complexity = O(N)********************************/
/***************Space Complexity = O(H)*******************************/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
       root1 -> val += root2 -> val;
        
       root1 -> left = mergeTrees(root1 -> left , root2 -> left);
       root1 -> right = mergeTrees(root1 -> right , root2 -> right);
        return root1;
    }
};

/***************Method - 2 *******************************************/
/***************Iterative DFS approach********************************/
/***************Approach to Merge Two Binary Trees********************/
/***************Time Complexity = O(N)********************************/
/***************Space Complexity = O(N)*******************************/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
      
      stack < pair<TreeNode * , TreeNode * >> st;
        st.push({root1 , root2});
        while(!st.empty()) {
            TreeNode *curr1 = st.top().first;
            TreeNode *curr2 = st.top().second;
            st.pop();
            curr1 -> val += curr2 -> val;
            //left Tree
            if(curr1 -> left == NULL) 
                curr1 -> left = curr2 -> left;
            else if(curr2 -> left != NULL) 
                st.push({curr1 -> left , curr2 -> left });

             //right Tree
            if(curr1 -> right == NULL) 
                curr1 -> right = curr2 -> right;
            else if(curr2 -> right != NULL) 
                st.push({curr1 -> right , curr2 -> right });

        }
        return root1;
    }
};

/***************Method - 3 *******************************************/
/***************Iterative BFS approach********************************/
/***************Approach to Merge Two Binary Trees********************/
/***************Time Complexity = O(N)********************************/
/***************Space Complexity = O(N)*******************************/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
      
      queue < pair<TreeNode * , TreeNode * >> st;
        st.push({root1 , root2});
        while(!st.empty()) {
            TreeNode *curr1 = st.front().first;
            TreeNode *curr2 = st.front().second;
            curr1 -> val += curr2 -> val;
            
            st.pop();
            if(curr1 -> left == NULL) 
                curr1 -> left = curr2 -> left;
            else if(curr2 -> left != NULL)
                st.push( {curr1 -> left , curr2 -> left });
            
            if(curr1 -> right == NULL) 
                curr1 -> right = curr2 -> right;
            else if(curr2 -> right != NULL)
                st.push( {curr1 -> right , curr2 -> right });

        }
        return root1;
    }
};
