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

/***********************Optimal Approach to Count Node with High Scores*********************/
/************************Time Complexity = O(N)****************************************/
/************************Space Complexity = O(h)***************************************/

class Solution {
    int dfs(vector<vector<int >> & allNodes , vector<long long > &sizeOfNodes , int ind) {
        long long prod = 1 , size = 1 , size_of_Tree = allNodes.size() ;
        
        for(int i : allNodes[ind]) {
            int count = dfs(allNodes , sizeOfNodes , i);
            prod *= count;
            size += count;
        }
        if(ind == 0 ) sizeOfNodes[ind] = prod ;
        else sizeOfNodes[ind] = prod *  ((long long )size_of_Tree - size);
        return size;
        
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
     vector<vector<int>> allNodes(n);
     vector<long long> sizeOfNode(n);
        
        for(int i = 1 ; i < n ;i++)
            allNodes[parents[i]].push_back(i);
        
    dfs(allNodes , sizeOfNode , 0);
        long long Max = INT_MIN;
        int count = 0;
        for(long long &x : sizeOfNode ) {
            cout<<x<<endl;
            if(x > Max) {
                Max = x;
                count = 1;
            }
            else if(x == Max) count++;
        }
        return count;
    }
};