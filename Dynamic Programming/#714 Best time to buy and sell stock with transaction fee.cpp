/******************** Optimal approach To Buy and sell stock********************************/
/*******************Time complexity = O(N)**************************************************/
/*******************Space complexity = O(N)  ***********************************************/

class Solution {
    int solve(int ind , bool buy, vector<int>&prices , int &fee , vector<vector<int>>&dp) {
        int n = prices.size();
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) {
            return dp[ind][buy] = max(solve(ind + 1 , false , prices , fee , dp) - prices[ind] , solve(ind + 1 , true , prices , fee , dp));
        } else {
            return dp[ind][buy] = max(solve(ind + 1 , true , prices , fee , dp) + prices[ind] - fee , solve(ind + 1 , false , prices , fee , dp));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp( n , vector<int>( 2 , -1));
        return solve(0 , true , prices , fee , dp);
    }
};