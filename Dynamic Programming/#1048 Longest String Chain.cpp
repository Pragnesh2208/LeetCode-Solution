/**
 * Optimal Solution using memoization
 * Time Complexity = O(N^2 * N)
 * Space Complexity = O(N^2)
 */

class Solution {

public:
static bool cmp (string a , string  b) {
    return a.length() < b.length();
}
    int solve(int ind , int prevInd, vector<string>&freq , vector<vector<int>>&dp) {
        int n = freq.size();
        if(ind == n) return 0;
        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];
        int take = prevInd == -1 || valid(freq[ind] , freq[prevInd]) ? solve(ind + 1 , ind , freq , dp) + 1: 0;
        int notTake = solve(ind + 1 , prevInd , freq , dp);
        return dp[ind][prevInd + 1] =  max(take , notTake);
    }

    bool valid(string &curr , string &prev) {
        int n = curr.length() , m = prev.length();
        if(n - m != 1) return false; 
        int diff = 0;
        int ind1 = 0 , ind2 = 0 ;

        while(ind1 < n && ind2 < m) {
            if(curr[ind1] != prev[ind2]) {
                ind1++;
                diff++;
            }else{
                ind1++;
                ind2++;
            }
        }

        if(diff == 0 && ind1 == n - 1) return true;

        return diff == 1 && ind1 == n && ind2 == m;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end(), cmp);
        vector<vector<int>>dp (n , vector<int>(n + 1 , -1));
        return solve(0 , -1 , words , dp);
    }
};