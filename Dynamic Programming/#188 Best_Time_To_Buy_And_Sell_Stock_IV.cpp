/*
Solution Using Memoization
Time Complexity = O(N*K)
Space Complexity = O(N*K)
Auxilary Space Complexity = O(N)
*/
class Solution {
    int getMaxProfit(int ind , bool buy , int cap , vector<int>&arr , vector<vector<vector<int>>>&dp) {
        if(cap == 0 || ind == arr.size()) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy) {
            return dp[ind][buy][cap] = max(
                getMaxProfit(ind + 1 , false , cap , arr , dp) - arr[ind],
                getMaxProfit(ind + 1 , true , cap , arr , dp)
            );
        } else {
            return dp[ind][buy][cap] = max(
                getMaxProfit(ind + 1 , true , cap - 1 , arr , dp) + arr[ind] , 
                getMaxProfit(ind + 1 , false , cap , arr , dp)
            );
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>(2 , vector<int>(k + 1 , -1)));
        return getMaxProfit(0,true,k,prices , dp);
    }
};

/*
Solution Using Tabulation
Time Complexity = O(N*K)
Space Complexity = O(N*K)
*/

class Solution {
    int tabulation(int k , vector<int>&arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp( n + 1, vector<vector<int>>(2 , vector<int>(k + 1 , 0)));

        for(int i = n - 1 ; i >= 0 ; i--) {
            for(int cap = k ; cap > 0 ; cap--) {
                dp[i][0][cap] = max(dp[i+1][1][cap-1] + arr[i], dp[i+1][0][cap]);
                dp[i][1][cap] = max(dp[i+1][0][cap] - arr[i] , dp[i+1][1][cap]);
            } 
        }
        return dp[0][1][k];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return tabulation( k , prices);
    }
};

/*
Solution Using Space Optimization
Time Complexity = O(N*K)
Space Complexity = O(K)
*/

class Solution {

    int spaceOptimization(int k , vector<int>&arr) {
        int n = arr.size();
        vector<vector<int>>prev (2 , vector<int>(k + 1 , 0));

        for(int i = n - 1 ; i >= 0 ; i--) {
            vector<vector<int>>curr (2 , vector<int>(k + 1 , 0));

            for(int cap = k ; cap > 0 ; cap--) {
                curr[0][cap] = max(prev[1][cap-1] + arr[i], prev[0][cap]);
                curr[1][cap] = max(prev[0][cap] - arr[i] , prev[1][cap]);
            } 
            prev = curr;
        }
        return prev[1][k];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return spaceOptimization( k , prices);
    }
};