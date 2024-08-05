/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/***********************Optimal Approach for Verticle Order Traversal of Binary Tree**************/
/************************Time Complexity = O(N*logn)***************************************************/
/************************Space Complexity = O(H)**************************************************/

class Solution {
public:
    void inorder(TreeNode * root , map<int ,  map <int , multiset<int>>>&mp , int y , int x) {
        if(root == NULL) return;
        mp[x][y].insert(root -> val);
        inorder(root -> left , mp , y + 1 , x - 1);
        inorder(root -> right , mp , y + 1 ,  x + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,  map <int , multiset<int>>>mp;
        inorder(root , mp , 0 , 0);
        for(pair<int, map <int , multiset<int>>> i : mp) {
            vector<int>temp;
            for(auto j : i.second) {
                temp.insert(temp.end() , j.second.begin() , j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};