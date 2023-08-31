/*
Solution Using Memoization
Time Complexity = O(N)
Space Complexity = O(N)
Auxilary Space Complexity = O(N)
*/

class Solution {
    int getMaxProfit(int ind , bool buy , vector<int>&arr , vector<vector<int>> &dp) {
        if(ind >= arr.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy) {
            return dp[ind][buy] =  max(
                getMaxProfit(ind + 1 , false , arr , dp) - arr[ind],
                getMaxProfit(ind + 1 , true , arr , dp)
            );
        }
        else {
            return dp[ind][buy] = max(
                getMaxProfit(ind + 2 , true , arr , dp) + arr[ind],
                getMaxProfit(ind + 1, false , arr , dp)
            );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp( n , vector<int>(2,-1));
       return getMaxProfit( 0 , true , prices , dp);
    }
};

/*
Solution Using Tabulation
Time Complexity = O(N)
Space Complexity = O(N)
*/

class Solution {
    int tabulation(vector<int>&arr) {
        int n = arr.size();
        vector<vector<int>> dp( n + 2 ,vector<int>(2 , 0));

        for(int i = n - 1 ; i >=0 ; i--) {
            dp[i][1] = max(dp[i + 1][0] - arr[i], dp[i + 1][1]);
            dp[i][0] = max(dp[i+2][1] + arr[i] , dp[i+1][0]);
        }
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        return tabulation(prices);
    }
};

/*
Solution Using Space Optimization
Time Complexity = O(N)
Space Complexity = O(1)
*/

class Solution {
    int spaceOptimization(vector<int>&arr) {
        int n = arr.size();
        vector<vector<int>> prev( 2 ,vector<int>(2 , 0));
        vector<int>curr(2 , 0);

        for(int i = n - 1 ; i >=0 ; i--) {
            curr[1] = max(prev[0][0] - arr[i], prev[0][1]);
            curr[0] = max(prev[1][1] + arr[i] , prev[0][0]);
            prev[1] = prev[0];
            prev[0] = curr;
        }
        return prev[0][1];
    }

public:
    int maxProfit(vector<int>& prices) {
        return spaceOptimization(prices);
    }
};