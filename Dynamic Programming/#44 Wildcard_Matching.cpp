/*
Time Complexity = O(M*N)
Space Complexitty = O(M*N)
Using Memoization
*/
class Solution {
    private:
    bool areMatching(string &s1 , string &s2  , int i , int j , vector<vector<int>> &dp) {
        if(i == 0) {
            if(j > 0 && s2[j - 1] == '*' ) return dp[i][j] = areMatching(s1, s2 , i , j -1 , dp);
            else if(j == 0)return dp[i][j] = true;
            else return dp[i][j] = false;
        }
        if(j == 0) return  dp[i][j] = false;

        if(dp[i][j] != -1) return dp[i][j];
        if(s2[j -1] != '*' && s2[j - 1]!='?'&& s1[i - 1] != s2 [j - 1]) return dp[i][j] =  false;
        bool flag = false;
        if(s2[j - 1] == '*') flag = areMatching(s1 , s2 , i - 1 , j , dp) || areMatching(s1 , s2 , i  , j - 1 , dp) ;
        if(!flag)
        flag = areMatching(s1 , s2 , i - 1, j - 1  , dp);
        return dp[i][j] = flag;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size() ,  m = p.size();
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1, -1));
        return areMatching(s , p  , n , m  , dp);
    }
};


/*
Time Complexity = O(M*N)
Space Complexitty = O(M*N)
Using Tabulation
*/
class Solution {
    private:

    bool tabulation(string &s1 , string &s2) {
        int n = s1.size()  , m = s2.size();
        vector<vector<int>> dp( n  + 1, vector<int>(m  + 1, 0));
        dp[0][0] = true;

        for(int i = 1 ; i <= m ; i++) {
            if(s2[i - 1] == '*') 
            dp[0][i] = dp[0][i-1];
        }

        for(int i = 1; i <= n ; i++) {
            for(int j = 1;  j <= m ; j++) {
                if(s1[i-1] == s2[j - 1] || s2[j - 1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(s2[j - 1] == '*'){
                    dp[i][j] = max(dp[i-1][j-1] , max(dp[i-1][j] , dp[i][j-1]));
                } else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }

public:
    bool isMatch(string s, string p) {
        return tabulation(s , p);
    }
};