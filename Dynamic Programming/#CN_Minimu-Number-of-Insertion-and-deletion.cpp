/*
Time complexity = O(N*M)
Space Complexity = O(N*M)
*/

int tabulation(string s1 , string s2 ) {
    int n = s1.size() ; 
    int m = s2.size();
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));

    for(int i = 1; i <= n ; i++) {
        for(int j = 1 ; j <= m  ; j++) {
            if(s1[i -1] != s2[j - 1])
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ; 
            else
                dp[i][j] = 1+  dp[i- 1][j -  1];   
        }
    }
  
    return  m + - dp[n][m] + n - dp[n][m];
}
int canYouMake(string &s1, string &s2){
    // Write your code here.
    
    return tabulation(s1,s2);
}

