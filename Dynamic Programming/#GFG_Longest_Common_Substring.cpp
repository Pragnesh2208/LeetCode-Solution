/**
 * @brief 
 * Note : we can't do same as we have done in Longest common subsequence as in this 
 * problem order matters
 * 
 */
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:

/****************Find Longest Common Substring using memoization*******************/
/****************Time Complexity = O(M * N)*************************************/
/****************Space Complexity = O(N * M)************************************/  
  
    int memoization(int ind1 , int ind2 , string &s1 , string &s2 , int &ans , vector<vector<int>>&dp ) {
        if(ind1 == -1 || ind2 == -1 ) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2] ;
    
        if(s1[ind1] == s2[ind2]) {
            dp[ind1][ind2] = 1 + memoization(ind1 - 1 , ind2 - 1 , s1  , s2 , ans , dp);
        }
        
        int dif1 = memoization(ind1 , ind2 - 1 , s1 , s2 , ans , dp);
        int dif2 = memoization(ind1 - 1, ind2  , s1 , s2 , ans , dp);
        
        dp[ind1][ind2]  = max(0 , dp[ind1][ind2]);
        
        ans = max(ans , dp[ind1][ind2]);
        return dp[ind1][ind2];
    }
    
/****************Find Longest Common Substring using tabulation*******************/
/****************Time Complexity = O(M * N)*************************************/
/****************Space Complexity = O(N * M)************************************/    

    int tabulation(string &s1 , string &s2 , int &n , int &m) {
      vector<vector<int>>dp(n , vector<int>(m,-1));
      
        int ans = 0;
        for(int ind2 = 0 ; ind2 < m  ; ind2++) {
            if(s1[0] == s2[ind2]) {
                dp[0][ind2] = 1;
                ans = 1;
            }
        }
        
        for(int ind1 = 1 ; ind1 < n ; ind1++) {
            for(int ind2 = 0 ; ind2 < m ; ind2++) {
    
                if(s1[ind1] == s2[ind2]) {
                    dp[ind1][ind2] = 1 +  dp[ind1 - 1] [ ind2 - 1];
                }

                dp[ind1][ind2]  = max(0 , dp[ind1][ind2]);
                ans = max(ans , dp[ind1][ind2]);
            }
        }
        return ans;
    }

/****************Find Longest Common Substring using space optmized*******************/
/****************Time Complexity = O(M * N)*************************************/
/****************Space Complexity = O(1)************************************/ 

    int optimized(string &s1 , string&s2 , int &n , int &m ){
        int ans = 0;
        for(int ind1 = 0 ; ind1 < n ; ind1++) {
            int tempI = 0 ;
            int count = 0;
            for(int ind2 = 0 ; ind2 < ind2 ; ind2++) {
                if(s1[tempI] == s2[ind2]) {
                    count++;
                    tempI++;
                    ans = max(count , ans);
                } else {
                    tempI = ind1 ;
                    count = 0;
                }
            }
        }
        return ans;
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m) {
        // your code here
        int ans = 0;
        vector<vector<int>>dp(n , vector<int>(m , -1));
        optimized(s1, s2 , n , m);
        tabulation(s1 , s2 , n , m);
        memoization( n - 1, m - 1, s1 , s2 , ans  , dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends