/*
Time Complexity = O(N)
Space Complexity = O(N)
Using Memoization
*/
class Solution {
    private:
    int countMaxProfit(int i , vector<int>&prices , bool canBuy , vector<vector<int>>&dp) {
        if(i == prices.size()) return 0;
        int profit = 0;

        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        if(canBuy) {
            profit = max(countMaxProfit(i + 1, prices , false , dp) - prices[i] , countMaxProfit(i + 1 , prices , true , dp));
        } else {
            profit = max(countMaxProfit(i + 1 , prices , true , dp) + prices[i] , countMaxProfit(i + 1 , prices , false , dp));
        }
        return dp[i][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp( n, vector<int>(2 , -1));
        return countMaxProfit(0 , prices , true , dp);
    }
};

/*
Time Complexity = O(N)
Space Complexity = O(N)
Using Tabulation
*/
class Solution {
    private:

    int tabulation(vector<int>&prices) {
         int n = prices.size();
        vector<vector<int>>dp( n + 1, vector<int>(2  , 0));

        for(int i = n - 1 ; i >= 0  ; i--) {
            dp[i][1] = max(dp[i + 1][0] - prices[i] , dp[i+1][1]);
            dp[i][0] = max(dp[i + 1][1] + prices[i] , dp[i+1][0]);
        }

        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        return tabulation(prices);
    }
};



/*
Time Complexity = O(N)
Space Complexity = O(1)
Using Space Optimization
*/
class Solution {
    private:

    int tabulation(vector<int>&prices) {
         int n = prices.size();
        vector<int>prev(2 , 0 );
        for(int i = n - 1 ; i >= 0  ; i--) {
            vector<int>cur(2 , 0);
            cur[1] = max(prev[0] - prices[i] , prev[1]);
            cur[0] = max(prev[1] + prices[i] , prev[0]);
            prev = cur;
        }

        return prev[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        return tabulation(prices);
    }
};