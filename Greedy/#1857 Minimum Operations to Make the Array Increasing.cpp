/********************************Optimal approach to Find Minimum Operation to Make Array increment********************/
/********************************Time Complexity  = O ( N ) ***********************************************************/
/********************************Space Complexity  = O ( 1 ) **********************************************************/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int prev = nums[0];
        int ans = 0;
        int n = nums.size();
        for(int i = 1 ; i < n ; i++ ) {

            ans += prev >= nums[i] ? (prev - nums[i]  + 1): 0;
            if(prev >= nums[i])
            prev = nums[i] + prev - nums[i] + 1 ;
            else
                prev = nums[i];
        }
        return ans;
    }
};