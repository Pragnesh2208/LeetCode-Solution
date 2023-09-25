/*
Time Complexity for recursion is exponential 
Approach Using Memoization
Time Complexity O(N^3)
Space Complexity = O(N^2)
Auxilary Space Complexity = O(N)
*/
class Solution {
    int mcm(int i , int j , vector<int>&cuts , vector<vector<int>>&dp) {
        if(i > j) return 0;
        int minCost = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int ind = i  ; ind <= j ; ind++) {
            int step = cuts[j + 1] - cuts[i - 1] + mcm(i , ind  - 1 , cuts , dp) + mcm(ind + 1  , j , cuts , dp);
            minCost = min(minCost , step);
        }
        return dp[i][j] =  minCost;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        vector<vector<int>> dp(cuts.size() , vector<int>(cuts.size() , -1));
        return mcm(1 , cuts.size() - 2  , cuts , dp);
    }
};

/*
Approach Using Tabulation
Time Complexity O(N^3)
Space Complexity = O(N^2)
*/
class Solution {
    
    int  tabulation(int n , vector<int>&cuts) {
        vector<vector<int>> dp(cuts.size() , vector<int>(cuts.size() , -1));
        int c = cuts.size();
        for(int i = c - 2 ;  i >= 1 ; i--) {
            for(int j = i ;  j <= c - 2; j++) {
                int minCost = INT_MAX;
                for(int ind = i  ; ind <= j ; ind++) {
                int step = cuts[j + 1] - cuts[i - 1] + mcm(i , ind  - 1 , cuts , dp) + mcm(ind + 1  , j , cuts , dp);
                minCost = min(minCost , step);
                dp[i][j] = minCost;
                }
            }
        }
        return dp[1][c - 2];
    }

    
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        return tabulation( n , cuts);
    }
};