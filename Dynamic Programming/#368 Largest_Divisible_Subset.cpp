/*
Solution Using Tabulation
Time Complexity = O(N^2)
Space Complexity = O(N)
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int>arr = nums;
        int n = nums.size();
        vector<int>hash(n);
        vector<int>ans;
        int maxi = 0 , maxScore = 0;
        for(int i = 0 ; i < n ; i++) hash[i]  = i ;
        vector<int>dp(n + 1 , 1);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if((arr[i] % arr[j] == 0|| arr[j] % arr[i] == 0) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                    if(dp[i] > maxScore) {
                        maxScore = dp[i];
                        maxi = i;
                    }
                } 
            }
        }
        
        int lastIndex = maxi;
        while(lastIndex != hash[lastIndex]) {
            ans.push_back(arr[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(arr[lastIndex]);

        reverse(ans.begin() , ans.end());
        return  ans;

    }
};