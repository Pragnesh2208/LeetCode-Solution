/*
Time Complexity for recursion solution is exponential
Solution using Memoization
Time Complexity = O(N^3)
Space Complexity = O(N^2)
Auxilary Space Complexity = O(N)
*/
class Solution {
    int mcm(int i , int j , vector<int>&nums , vector<vector<int>>&dp) {
        if(i > j ) return 0;
        int maxCoin = 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int ind = i ; ind <= j ; ind++) {
            int coin = nums[i - 1] * nums[ind] * nums[j + 1] + mcm(i , ind - 1 , nums , dp) + mcm(ind + 1 , j , nums , dp);
            maxCoin = max(maxCoin , coin);
        }
        return  dp[i][j] = maxCoin;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size() , vector<int>(nums.size() , -1));
        return mcm(1 , nums.size() - 2 , nums , dp);
    }
};


/*
Solution using Tabulation
Time Complexity = O(N^3)
Space Complexity = O(N^2)
*/
class Solution {
    int tabulation(vector<int>&nums) {
        int n = nums.size();
        vector<vector<int>>dp(nums.size() , vector<int>(nums.size() , 0));

        for(int i = n - 2 ; i >= 1 ; i--) {
            for(int j = i ; j <= n - 2 ; j++) {
                int maxCoin = 0;
                for(int ind = i ; ind <= j ; ind++) {
                    int coin = nums[i - 1] * nums[ind] * nums[j + 1] + mcm(i , ind - 1 , nums , dp) + mcm(ind + 1 , j , nums , dp);
                    maxCoin = max(maxCoin , coin);
                }
                dp[i][j] = maxCoin;
            }
        }
        return dp[1][n-2];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        return tabulation(nums);
    }
};