/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N * 32)
 * Space Complexity = O(1)
 * 
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < 32 ; i++) {
            int ones = 0 , zeros = 0;
            for(int j = 0 ; j < n ; j++) {
                if(nums[j] & (1 << i)) ones++;
                else zeros++;
            }

            ans += (ones * zeros);
        }
        return ans;
    }
};