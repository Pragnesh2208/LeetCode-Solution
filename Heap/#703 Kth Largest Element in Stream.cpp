/***********************Optimal Solution using heap**************************/
/***********************Time Complexity = O(NLogK)***************************/
/***********************Space Complexity = O(K)******************************/

class KthLargest {
private:
    priority_queue<int , vector<int> , greater<int>> minHeap;
    int limit;

public:
    KthLargest(int k, vector<int>& nums) {
        this -> limit = k;
        int n = nums.size();

        for(int i = 0; i < n ; i++) {
            minHeap.push(nums[i]);
            if(minHeap.size() > k ) minHeap.pop();
        }
    }
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > limit ) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */