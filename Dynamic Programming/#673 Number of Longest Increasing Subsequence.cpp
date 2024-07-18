/*
Time Complexity = O(N ^ 2)
Space Complexity = O(N)
Using Tabulation
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp( n  , 1);
        vector<int>cnt(n , 1);
        int ans = 0 , maxi = 0;
        for(int i = 0 ; i < n ;i++) {
            for(int prev = 0; prev < i ; prev++) {
                if(nums[prev] < nums[i] ){
                    if( dp[prev] + 1 > dp[i]) {
                        dp[i] = 1 + dp[prev];
                        cnt[i] = cnt[prev];
                    } else if(dp[prev] + 1 == dp[i]) {
                        cnt[i]+= cnt[prev];
                    }
                }
            }
            if(maxi == dp[i]) {
                ans += cnt[i];
            }
            if(maxi < dp[i]) {
                maxi = dp[i];
                ans = cnt[i];
            }
        }

        return ans;
    }
};