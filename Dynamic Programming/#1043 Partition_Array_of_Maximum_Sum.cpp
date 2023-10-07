/*
Solution Using Recursion
Time Complexity = Exponential
Space Complexity = O(1)
Auxilary Space Complexity = O(N)

Solution Using Memoization
Time Complexity = O(N*K)
Space Complexity = O(N)
Auxilary Space Complexity = O(N)
*/
class Solution {
    int frontPartition(int i , int j , vector<int>&arr , int k  , vector<int>&dp) {
        if(i >= j) return 0;
        if(dp[i] != -1) return dp[i];
        int maxSum = 0;
        int maxEle = 0;
        for(int l = i; l < i + k && l < j; l++) {
            maxEle = max(maxEle , arr[l]);
            int curSum = maxEle * (l - i + 1) +  frontPartition(l + 1 , j , arr , k , dp);
            maxSum = max(curSum , maxSum);
        }
        return dp[i] = maxSum;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n , -1);
        return frontPartition( 0 , n , arr ,k , dp);
    }
};
/*
Solution Using Tabulation
Time Complexity = O(N*K)
Space Complexity = O(N)
Auxilary Space Complexity = O(1)
*/
class Solution {
    int tabulation(vector<int>&arr , int k) {
        int n = arr.size();
        vector<int>dp(n + 1 , 0);
        for(int i = n - 1 ; i >= 0 ; i--) {
            int maxSum = 0;
            int maxEle = 0;
            for(int l = i; l < i + k && l < n; l++) {
                maxEle = max(maxEle , arr[l]);
                int curSum = maxEle * (l - i + 1) +  dp[l + 1];
                maxSum = max(curSum , maxSum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return tabulation(arr , k);
    }
};