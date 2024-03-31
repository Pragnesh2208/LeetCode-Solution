/***********************Optimal Solution using heap + greedy ************************/
/***********************Time Complexity = O(NLogN)***************************/
/***********************Space Complexity = O(N)******************************/

class Solution {
public:

static bool myCmp(pair<int,int>a , pair<int,int>b) {
    return a.first < b.first;
}
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> project;
        priority_queue<int> maxHeap;
        int n = profits.size();
        int ans = w;
        for (int i = 0; i < n; i++)
            project.push_back({capital[i], profits[i]});

        sort(project.begin(), project.end() , myCmp);
        int ptr = -1;
        while (k--) {
            for (int i = ptr + 1; i < n && project[i].first <= w; i++) {
                maxHeap.push(project[i].second);
                ptr = i;
            }

            int topProfit = 0;
            if(!maxHeap.empty()) {
                topProfit = maxHeap.top();
                maxHeap.pop();
            }
            ans += topProfit;
            w += topProfit;
        }

        return ans;
    }
};