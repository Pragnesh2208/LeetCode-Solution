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
/**********************Optimal Approach for Binary Search Tree Iterator*************************/
/*********************Time complexity = O (N)***************************************************/
/**********************Space complexity = O (H)*************************************************/
class BSTIterator {
    TreeNode * point ;
    stack<TreeNode * > st;
public:
    BSTIterator(TreeNode* root) {
     point = root;
        while(point ) {
            st.push(point);
            point = point -> left;
        }
    }
    
    int next() {
      int ans = st.top() -> val;
      TreeNode * temp = st.top();
        
      st.pop();
      
      if(temp -> right) {
          TreeNode * n = temp -> right;
          while(n )
          {
              st.push(n);
              n = n -> left;
          }   
      }
      return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */