/***********************Optimal Approach for Bottom view of Binary Tree**************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(N)**************************************************/

class Solution {
  public:
  void inorder(Node * root , vector<vector<int>>&ans , vector<int>&temp) {
      if(root -> left == NULL && root -> right == NULL) {
          temp.push_back(root -> data);
          ans.push_back(temp);
          temp.pop_back();
          return;
      }
      temp.push_back(root -> data);
      if(root -> left) inorder(root -> left , ans , temp);
      if(root -> right) inorder(root -> right , ans , temp);
    temp.pop_back();
      
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        vector<int>temp;
        inorder(root , ans , temp);
        return ans;
    }
};