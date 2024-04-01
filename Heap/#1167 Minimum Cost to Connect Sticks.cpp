/***********************Optimal Solution using heap +  Greedy**************************/
/***********************Time Complexity = O(NLogN)***************************/
/***********************Space Complexity = O(N)******************************/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int> , greater<int>>minHeap;
        int n = sticks.size();
        for(int i = 0 ; i < n ;i++) {
            minHeap.push(sticks[i]);
        }
        int ans = 0;
        while(minHeap.size() > 1) {
            int firstEle = minHeap.top();
            minHeap.pop();
            int secondEle = minHeap.top();
            minHeap.pop();
            ans += firstEle + secondEle;
            minHeap.push(firstEle + secondEle);
        }

        return ans;
    }
};