/* Optimal Solution
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int psign = 0 , nsign = 0;
        int ans  = 0  , n = nums.size();
        for(int i = 1 ; i < n  ; i++) {
            if(nums[i] - nums[i - 1] < 0) {
                ans = max(ans , psign + 1);
                nsign = max(nsign , psign + 1);
            } else if(nums[i] - nums[i-1] > 0) {
                ans = max(ans , nsign + 1);
                psign = max(psign , nsign + 1);
            }
        }

        return ++ans;
    }
};