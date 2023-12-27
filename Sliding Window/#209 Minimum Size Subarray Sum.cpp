/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int ans = -1;
        int start = 0 ;
        int sum = 0 ;

        for(int end = 0 ; end < n ; end++) {
           
            sum += nums[end];
            while(sum >= target) {
                sum -= nums[start];
                if(ans == -1) ans = end - start + 1;
                else
                ans = min(ans , end - start + 1);
                start++;
            }
        }

        if(ans == -1) return 0;
        return ans;

    }
};