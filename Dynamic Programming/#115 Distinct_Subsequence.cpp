/*
Time Complexity = O(N*M)
Space Complexity = O(N*M)
Using Memoization
*/
class Solution {
    private:
    int subsequence(string &s , string &t , int n , int m , vector<vector<int>>&dp) {
        if( m < 0 ) return 1;
        if(n < 0 )return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int cnt = 0;
        if(s[n] == t[m] )
        cnt += subsequence(s , t , n - 1 , m - 1 , dp);
        cnt += subsequence(s , t , n - 1 , m , dp);
        return dp[n][m] = cnt ;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size() -1 , m = t.size() - 1;
        vector<vector<int>>dp( n + 1 , vector<int>(m  +1, -1));
        return subsequence(s ,t , n , m , dp);      
    }
};

/*
Time Complexity = O(N*M)
Space Complexity = O(N*M)
Using Tabulation
*/

class Solution {
    private:

    int tabulation(string &s , string &t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>>dp( n + 1, vector<long long>(m + 1, 0 ));
        for(int i = 0 ; i <= n ;i++) dp[i][0] = 1;

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1;  j <= m ; j++) {
                
                int temp = 0;
                if(s[i-1] == t[j-1])temp = dp[i-1][j-1];
                dp[i][j] = dp[i-1][j] + temp;
            }
        }
        
        return dp[n][m];
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size() -1 , m = t.size() - 1;
        return tabulation(s , t);
    }
};

/*
Time Complexity = O(N*M)
Space Complexity = O(M)
Using Space Optimization
*/
class Solution {
    private:
    int subsequence(string &s , string &t , int n , int m , vector<vector<int>>&dp) {
        if( m < 0 ) return 1;
        if(n < 0 )return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int cnt = 0;
        if(s[n] == t[m] )
        cnt += subsequence(s , t , n - 1 , m - 1 , dp);
        cnt += subsequence(s , t , n - 1 , m , dp);
        return dp[n][m] = cnt ;
    }

    int tabulation(string &s , string &t) {
        int n = s.size();
        int m = t.size();

        vector<double>dp(m + 1 , 0);
        dp[0] = 1;

        for(int i = 1 ; i <= n ; i++) {
            for(int j = m ;  j >= 1 ; j--) {
                if(s[i-1] == t[j-1]) dp[j] = dp[j-1] + dp[j];
            }
        }
        
        return (int)dp[m];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size() -1 , m = t.size() - 1;
        vector<vector<int>>dp( n + 1 , vector<int>(m  +1, -1));
        return tabulation(s , t);
        return subsequence(s ,t , n , m , dp);      
    }
};