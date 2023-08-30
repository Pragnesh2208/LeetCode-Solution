/*
Solution Using Memoization
Time Complexity = O(N)
Space Complexity = O(N*2*3)
Auxilary Space Complexity = O(N)
*/
class Solution {
    private : 
   int getMaxProfit(int ind , int buy , int cap , vector<int>&arr , vector<vector<vector<int>>>&dp ) {
        if(cap == 0 || ind == arr.size() ) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy) {
            return dp[ind][buy][cap] = max(
                getMaxProfit(ind + 1 , 0 , cap , arr , dp) - arr[ind] ,
                getMaxProfit(ind + 1, 1 , cap , arr , dp)
            );
        }
        else {
            return dp[ind][buy][cap] =  max (
                getMaxProfit(ind + 1 , 1 , cap - 1 , arr , dp ) + arr[ind],
                getMaxProfit(ind + 1 , 0 , cap  ,arr , dp)
            );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>(2 , vector<int>( 3, -1)));
        return getMaxProfit(0 , 1 , 2 , prices , dp);
    }
};


/*
Solution Using Tabulation
Time Complexity = O(N)
Space Complexity = O(N*2*3)
*/

class Solution {
    private : 
   int getMaxProfit(int ind , int buy , int cap , vector<int>&arr , vector<vector<vector<int>>>&dp ) {
        if(cap == 0 || ind == arr.size() ) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy) {
            return dp[ind][buy][cap] = max(
                getMaxProfit(ind + 1 , 0 , cap , arr , dp) - arr[ind] ,
                getMaxProfit(ind + 1, 1 , cap , arr , dp)
            );
        }
        else {
            return dp[ind][buy][cap] =  max (
                getMaxProfit(ind + 1 , 1 , cap - 1 , arr , dp ) + arr[ind],
                getMaxProfit(ind + 1 , 0 , cap  ,arr , dp)
            );
        }
    }

    int tabulation(vector<int>&arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp( n + 1 , vector<vector<int>>(2 , vector<int>( 3, 0)));

        for(int i = n - 1 ; i >= 0 ; i--) {
            for(int j = 1 ; j <= 2 ;  j++) {
                dp[i][1][j] = max(dp[i+1][0][j] - arr[i] , dp[i + 1][1][j]);
                dp[i][0][j] = max(dp[i+1][1][j-1] + arr[i] , dp[i+1][0][j]);
            }
        }
        return dp[0][1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        return tabulation(prices);
        int n = prices.size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>(2 , vector<int>( 3, -1)));
        return getMaxProfit(0 , 1 , 2 , prices , dp);
    }
};

/*
Solution Using Space Optimization
Time Complexity = O(N)
Space Complexity = O(1)
*/

class Solution {
    private : 
   int getMaxProfit(int ind , int buy , int cap , vector<int>&arr , vector<vector<vector<int>>>&dp ) {
        if(cap == 0 || ind == arr.size() ) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy) {
            return dp[ind][buy][cap] = max(
                getMaxProfit(ind + 1 , 0 , cap , arr , dp) - arr[ind] ,
                getMaxProfit(ind + 1, 1 , cap , arr , dp)
            );
        }
        else {
            return dp[ind][buy][cap] =  max (
                getMaxProfit(ind + 1 , 1 , cap - 1 , arr , dp ) + arr[ind],
                getMaxProfit(ind + 1 , 0 , cap  ,arr , dp)
            );
        }
    }

    int tabulation(vector<int>&arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp( n + 1 , vector<vector<int>>(2 , vector<int>( 3, 0)));

        for(int i = n - 1 ; i >= 0 ; i--) {
            for(int j = 1 ; j <= 2 ;  j++) {
                dp[i][1][j] = max(dp[i+1][0][j] - arr[i] , dp[i + 1][1][j]);
                dp[i][0][j] = max(dp[i+1][1][j-1] + arr[i] , dp[i+1][0][j]);
            }
        }
        return dp[0][1][2];
    }

    int spaceOptimization(vector<int>&arr) {
        int n = arr.size();
       vector<vector<int>> prev(2 , vector<int>(3 , 0));

        for(int i = n - 1 ; i >= 0 ; i--) {
            vector<vector<int>> curr(2 , vector<int>(3 , 0));
            for(int j = 1 ; j <= 2 ;  j++) {
                curr[1][j] = max(prev[0][j] - arr[i] , prev[1][j]);
                curr[0][j] = max(prev[1][j-1] + arr[i] , prev[0][j]);
            }
            prev = curr;
        }
        return prev[1][2];
    }

public:
    int maxProfit(vector<int>& prices) {
        return spaceOptimization(prices);
        return tabulation(prices);
        int n = prices.size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>(2 , vector<int>( 3, -1)));
        return getMaxProfit(0 , 1 , 2 , prices , dp);
    }
};