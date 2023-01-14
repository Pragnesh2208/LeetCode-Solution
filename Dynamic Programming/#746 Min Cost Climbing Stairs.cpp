/********************Memoization Technique to solve Min Cost Climbing Stairs***************/
/********************Time Complexity = O(N)************************************************/
/********************Space Complexxity = O(N)**********************************************/
class Solution {
    int memoization(vector<int>&cost , int index , vector<int>&dp) {
        int n = cost.size();
        if(index >= n) return 0;
        if(dp[index] == -1) 
        dp[index] = cost[index] + min(memoization(cost , index + 1 , dp) , memoization(cost , index + 2 , dp));
        return dp[index];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1 , -1);
       memoization(cost , 0 , dp);
       return min(dp[0] , dp[1]);
    }
};

/********************Tabulation Technique to solve Min Cost Climbing Stairs***************/
/********************Time Complexity = O(N)************************************************/
/********************Space Complexxity = O(N)**********************************************/
class Solution {
    void tabulation(vector<int>&cost , vector<int>&dp) {
        int n = cost.size();
        for(int i = n-1 ; i >= 0 ; i--) {
            if(i+1 >=n || i + 2 >= n) dp[i] = cost[i];
            else 
            dp[i] = cost[i] +min(dp[i+1] , dp[i+2]);
        }
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1 , -1);
       tabulation(cost, dp);
       return min(dp[0] , dp[1]);
    }
};

/********************Optimal Approach to solve Min Cost Climbing Stairs***************/
/********************Time Complexity = O(N)************************************************/
/********************Space Complexxity = O(N)**********************************************/
class Solution {
    int Optimized(vector<int>&cost ) {
        int n = cost.size();
        int secondLast = cost[n-2] , last = cost[n-1]; 
        for(int i = n-3 ; i >= 0 ; i--) {
          int cur  = cost[i] +min(secondLast , last);
          last = secondLast;
          secondLast = cur;
        }
        return min(last , secondLast);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1 , -1);
       return Optimized(cost);  
    }
};