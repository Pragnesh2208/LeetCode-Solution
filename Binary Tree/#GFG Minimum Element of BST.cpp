/*********************Optimal Approach for Minimum Element of BST*************/
/*********************Time complexity = O (N )********************************/
/**********************Space complexity = O (H)*******************************/

class Solution {
  public:
    int minValue(Node* root) {
        if(root -> left) return minValue(root -> left);
        return root -> data;
    }
};
