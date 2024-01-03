class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sz = nums.size();
        int sum = 0 ;
        int target = 0;
        int lengthOfLongestSum = -1;
        for(int i = 0 ; i < sz ; i++) sum += nums[i];
        target = sum - x;
        sum = 0;
        for(int end = 0 , start = 0 ; end < sz ; end++) {
            sum += nums[end];
            while(sum > target && start <= end) {
                sum -= nums[start++];
            }
            if(sum == target)
            lengthOfLongestSum = max(lengthOfLongestSum , end - start + 1);
        }

        if(lengthOfLongestSum == -1) return -1;
        return sz - lengthOfLongestSum;
    }
};