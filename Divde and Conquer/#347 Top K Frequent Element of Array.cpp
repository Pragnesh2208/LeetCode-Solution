/************************Optimal solution to find Top K Frequent Element of Array Using Divide And Conquer*************************/
/************************Time Complexity = O(N)**************************************************/
/************************Space Complexity = O(N)*************************************************/
/****************************Refer video of NeetCode*********************************/
/************************Here we can also refer bucket sort or quick sort solution but wrost case goes to O(N^2)******************/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        vector<int,vector<int>>freq(nums.size() + 1);
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

/************************Better solution to find Top K Frequent Element of Array using Heap*************************/
/************************Time Complexity = O(NLOGK)**************************************************/
/************************Space Complexity = O(N)*************************************************/

class myComp{
    public:
    bool operator()(pair<int,int> a , pair<int,int>b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , myComp>minHeap;
        int n = nums.size();
        unordered_map<int,int>bucket;
        vector<int> ans;

        for(int i = 0 ; i < n ;i++) {
            bucket[nums[i]]++;
        }

        for(auto p : bucket) {
            minHeap.push({p.first , p.second});
            if(minHeap.size() > k) minHeap.pop();
        }

        while(!minHeap.empty()) {
            int topEle = minHeap.top().first;

            minHeap.pop();
            ans.push_back(topEle);
        }

        return ans;
    }
};