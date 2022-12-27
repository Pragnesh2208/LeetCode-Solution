/************************Optimal solution to find Top K Frequent Element of Array*************************/
/************************Time Complexity = O(N)**************************************************/
/************************Space Complexity = O(N)*************************************************/
/****************************Refer video of NeetCode*********************************/
/************************Here we can also refer bucket sort or quick sort solution but wrost case goes to O(N^2)******************/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        unordered_map<int,vector<int>>freq;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) count[nums[i]]++;

        for(pair<int,int>p : count) {
            freq[p.second].push_back(p.first);
        }

        for(int i = n ; i >=0 && ans.size() != k ; i--) {
            int size =freq[i].size(); 
            int j = 0;
            while (size != 0 && ans.size() != k) {
                ans.push_back(freq[i][j++]);
                size--;
            }
        }
    return ans;
    }
};