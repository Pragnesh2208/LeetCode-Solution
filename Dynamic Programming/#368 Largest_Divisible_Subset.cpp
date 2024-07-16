/*
Solution Using Memoization
Time Complexity = O(N^2)
Space Complexity = O(N^2)
*/
class Solution {
    int solve(int ind , int prevInd , vector<int>&arr , vector<vector<int>>&dp) {
        int n = arr.size();
        if(ind == n) return 0;
        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];
        int take = prevInd == -1 || (arr[ind] % arr[prevInd] == 0) ? solve(ind + 1 , ind , arr , dp) + 1 : 0;
        int notTake = solve(ind + 1 , prevInd , arr , dp);
        return dp[ind][prevInd + 1] = max(take , notTake);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<vector<int>>dp( n  + 1, vector<int>( n + 1 , -1));
        sort(nums.begin() , nums.end());
        solve(0 , -1 , nums,dp);
        for(int prev = 0 ; prev <= n ;prev++) dp[n][prev] = 0;

        int ind = 0 , prevInd =  -1 ;
        while(ans.size() != dp[0][0] && ind < n) {
            bool flag = true;
            if (ans.size() >= 1) {
                flag = nums[ind] % ans.back() == 0;
            }
            if(flag && dp[ind][prevInd + 1] == dp[ind + 1][ind + 1] + 1) {
            
                ans.push_back(nums[ind]);
                prevInd = ind ;
                ind++;
            } else ind++;
        }
        return ans;
    }
};


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