/**************Approach by Tabulation Technique******************/
/**************Time Complexity = O(N)****************************/
/**************Space Complexity = O(N)**************************/
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1 , 0);
        dp[1] = 1;
        if(n>=2)  dp[2] = 2;
        for(int i = 3 ; i<= n ; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/**************Optimal Solution to Solve Climbing Stairs*****************/
/**************Time Complexity = O(N)****************************/
/**************Space Complexity = O(1)**************************/

class Solution {

public:
    int climbStairs(int n) {
       int prev1 = 1 , prev2 = 2;
       int ans;
       if(n == 1) ans = 1;
       if(n == 2) ans = 2;
       for(int i = 3 ; i <= n ; i++) {
           ans = prev1 + prev2;
           prev1 = prev2;
           prev2 = ans;
       } 
       return ans;
    }
};