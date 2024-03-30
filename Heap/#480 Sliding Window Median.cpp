/***********************Optimal Solution using 2 heaps and hashmap***************/
/***********************Time Complexity = O(NLogN)*******************************/
/***********************Space Complexity = O(N)**********************************/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        vector<double> ans;

        unordered_map<int, int> extra;

        int n = nums.size();
        for (int i = 0; i < k; i++) {
            maxHeap.push(nums[i]);
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        if (k % 2) {
            ans.push_back(maxHeap.top());
        } else {
            double temp = minHeap.top();
            temp += maxHeap.top();
            ans.push_back(temp / 2.0);
        }
        for (int i = k; i < n; i++) {
            int prevEle = nums[i - k];
            int median = ans.back();
            int balance = 0;
            extra[prevEle]++;
            // if prevEle <= median then , it must be inside maxHeap
            // so if prevEle is in maxHeap , then we can  say that (have one extra element ( bad element ) in maxHeap) or (maxHeap have one less element to find the median of current window)

            if (prevEle <= median) {
                balance = 1;
            } else
                balance = -1;
            
            // if the current_num  we need to push is less than median , means it goes in maxHeap
            // so if we are pushing it into maxHeap
            // we are nullifying the effect of oneExtra element in maxHeap by doing balance--;
            if (nums[i] <= median) {
                balance--;
                maxHeap.push(nums[i]);
            } else {
                balance++;
                minHeap.push(nums[i]);
            }

            // if balance > 0 is possible if
            // one bad element was in maxHeap and we also pushed current_num to minHeap
            // so now to balance our heaps , we need to move minHeap element to maxHeap;
            
            if (balance > 0) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else if (balance < 0) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            while (!maxHeap.empty() && extra[maxHeap.top()] > 0) {
                extra[maxHeap.top()]--;
                maxHeap.pop();
            }

            while (!minHeap.empty() && extra[minHeap.top()] > 0) {
                extra[minHeap.top()]--;
                minHeap.pop();
            }

            if (k % 2) {
                ans.push_back(maxHeap.top());
            } else {
                double temp = minHeap.top();
                temp += maxHeap.top();
                ans.push_back(temp / 2.0);
            }
        }
        return ans;
    }
};