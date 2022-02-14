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

/**********************Optimal Approach for All Elements in Two Binary Search Trees*****************/
/*********************Time complexity = O (N + M)*******************************************************/
/**********************Space complexity = O (N + M)*****************************************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<int> & arr) {
        if(root == NULL)
            return;
        inorder(root -> left , arr);
        arr.push_back(root -> val);
        inorder(root -> right  , arr);
    }
    private:
    vector<int> mergeArray (vector<int> &a1 , vector<int> &a2) {
        int l1 = a1.size();
        int l2 = a2.size();
        vector<int>a3;
        int p1 = 0 , p2 = 0;
        while(p1 < l1 && p2 < l2) {
            
            if(a1[p1] < a2[p2]) 
                a3.push_back(a1[p1++]);
            else 
                a3.push_back(a2[p2++]);
                  
        }
        if(p1 != l1)
            a3.insert(a3.end(), a1.begin() + p1  , a1.end());
        if(p2 != l2)
            a3.insert(a3.end()  ,a2.begin() + p2  , a2.end());
        return a3;
        
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1 , arr2;
        inorder(root1 , arr1);
        inorder(root2 , arr2);
       
        return mergeArray(arr1 , arr2);
    }
};