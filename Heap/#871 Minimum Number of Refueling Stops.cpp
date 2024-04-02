/***********************Optimal Solution using heap +  Greedy**************************/
/***********************Time Complexity = O(NLogN)***************************/
/***********************Space Complexity = O(N)******************************/

class Solution {
public:
    int minRefuelStops(int target, int startFuel,
        vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        sort(stations.begin(), stations.end());

        int n = stations.size();
        long long ans = 0, fuel = startFuel;
        long long journey = 0;

        for (int i = 0; i < n; i++) {
            while (target - journey > fuel &&  (journey + fuel) < stations[i][0]) {
                if (maxHeap.empty())
                    return -1;
                int tempFuel = maxHeap.top();
                maxHeap.pop();
                fuel += tempFuel;
                ans++;
            }

            if (target - journey <= fuel)
                return ans;

            maxHeap.push(stations[i][1]);
            journey += stations[i][0];
            fuel -= stations[i][0];
        }

        journey += fuel;
        while (!maxHeap.empty() && target > journey) {
            int topEle = maxHeap.top();
            maxHeap.pop();
            journey += topEle;
            ans++;
        }

        if (journey < target) {
            return -1;
        }

        return ans;
    }
};