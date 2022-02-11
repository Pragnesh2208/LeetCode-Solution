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
/*********************Brute Force Approach for Second Minimum element in Binary Tree******************/
/*********************Time complexity = O (NLOGN)***************************************/
/**********************Space complexity = O (H + N)*************************************/
class Solution {
    private:
    void inorder(TreeNode * root , vector<int> &arr) {
        if(root == NULL)
            return ;
        inorder(root -> left ,  arr); 
arr.push_back(root -> val);
        inorder(root -> right , arr);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr );
        sort(arr.begin() , arr.end() );
        int i = 0;
        while( i< arr.size() && arr[i] == arr[0])
            i++;
        return i >= arr.size() ? -1 : arr[i];
    }
};
/*********************Optimal Approach for Second Minimum element in Binary Tree******************/
/*********************Time complexity = O (NLOGN)***************************************/
/**********************Space complexity = O (H + N)*************************************/
class Solution {
    private:
    void inorder(TreeNode * root , set<int > &arr) {
        if(root == NULL)
            return ;
        inorder(root -> left ,  arr); 
arr.insert(root -> val);
        inorder(root -> right , arr);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> arr;
        inorder(root, arr );
        for(auto &p : arr)
            cout<<p<<endl;
        arr.erase(arr.begin());
        return arr.size() > 0 ? *arr.begin() : -1;
    }
};