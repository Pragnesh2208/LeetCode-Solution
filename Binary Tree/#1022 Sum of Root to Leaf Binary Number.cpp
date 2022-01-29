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

/**********************************Method - 1***********************/
/***************************Brute Force recursive Approach for Sum of root to leaf in Binary Search Trees********************/
/***************************Time complexity = O (N) *************************************/
/***************************Space Complexity = O (H) ************************************/
class Solution {
    private :
       void preorder(TreeNode * root , int currNum , int &sum ) {
          if(root == NULL)
              return;
           currNum = (currNum << 1) + root -> val;
           if(root -> left == NULL && root -> right == NULL) 
               sum += currNum;
           preorder(root -> left , currNum , sum);
           preorder(root -> right , currNum , sum);
           
       }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        preorder(root , 0 , sum);
        return sum;
    }
};
/********Method - 2***********************/
/***************************Brute Force Iterative Approach for Sum of root to leaf in Binary Search Trees********************/
/***************************Time complexity = O (N) *************************************/
/***************************Space Complexity = O (N) ************************************/
class Solution {
    private :
       void preorder(TreeNode * root , int &sum ) {
          stack<pair<TreeNode *  , int >> st;
           if(root == NULL)
               return;
           st.push(make_pair(root , root-> val));
           while(!st.empty()) {
                TreeNode * curNode = st.top().first;
                int curVal = st.top().second;
               st.pop();
               if(curNode -> left != NULL) {
                   int Val = (curVal << 1) + curNode -> left -> val;
                   st.push(make_pair(curNode -> left , Val));
               }
               if(curNode -> right != NULL) {
                   int Val = (curVal << 1) + curNode -> right -> val;
                   st.push(make_pair(curNode -> right , Val));
               }
               if(curNode -> left == NULL && curNode -> right == NULL) {
                   sum += curVal  ;
               }  
            } 
       }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        preorder(root ,sum);
        return sum;
    }
};
/***********************************************Method - 3***********************/
/***************************Optimal Approach for Sum of root to leaf in Binary Search Trees using Morris Traversal********************/
/***************************Time complexity = O (N) *************************************/
/***************************Space Complexity = O (1) ************************************/
class Solution {
    private:
   void preorder(TreeNode * root , int &sum) {
       int curSum = 0;
       while(root != NULL) {
           if(root -> left == NULL) {
               curSum = (curSum << 1) + root -> val;
             if(root -> right == NULL) 
                 sum += curSum;
               root = root -> right;
           }
           else {
                 TreeNode *pre = root -> left;
                int step = 1;
               while(pre -> right && pre -> right != root) 
               {
                   step++;
                   pre = pre -> right;
               }
               if(pre -> right == root) {
                   pre -> right = NULL;
                   
                   if(pre -> left == NULL)
                       sum += curSum;
                   for(int i = 0 ; i < step ; i++)
                       curSum = (curSum >>1 );
                   root = root -> right;
                   
               }
               else {
                   pre -> right = root;
                   curSum = (curSum << 1 ) + root -> val;
                   root = root -> left;
               }
           }
       }
         
   }
       public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        preorder(root,sum );
        return sum;
    }
};