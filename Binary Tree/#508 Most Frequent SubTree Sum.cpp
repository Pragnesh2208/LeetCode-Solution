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
/***********************Optimal Approach To Find Most Frequent SubTree Sum****************/
/************************Time Complexity = O(N)***************************************************/
/************************Space Complexity = O(N)**************************************************/
class Solution {
    private:
    int maxCount = 0;
  
    int dfs(TreeNode * root ,unordered_map<int , int >&map ) {
        if(root == NULL)
            return 0;
        
        int ls = dfs(root -> left  , map);
        int rs = dfs(root -> right  , map);
        int sum = root -> val + ls +rs ;
        
        map[sum]++;
        maxCount = max(maxCount , map[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int>map;
        vector<int>ans; 
        dfs(root , map);
        //iterating map
       /* for(pair< const int ,int> &i : map)
           cout<<i.first<<endl;
         */   
        for(pair<const int , int > itr :map)
            if(itr.second == maxCount)
                ans.push_back(itr.first);
        return ans;
        
    }
};