/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>bucket;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int end = 0 , start = 0 ; end < n ; end++) {
            bucket[nums[end]]++;
            sum += nums[end];
            while(bucket[nums[end]] != 1) {
                bucket[nums[start]]--;
                sum -= nums[start++];
            }

            ans = max(ans , sum);
        }
        return ans;
    }
};