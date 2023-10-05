/*
Solution Using Recusrion
Time Complexity = Exponential
Space Complexity = O(1)
Auxilary Space Complexity = O(N)

Solution Using Memoization
Time Complexity = O(N^3)
Space Complexity = O(N)
Auxilary Space Complexity = O(N) 
*/
class Solution {
    bool isPalindrom(int i , int  j , string &s ) {
        while(i < j )
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    
    int frontPartition(int i , int j , string &s , vector<int>&dp) {
        if(dp[i] != -1) return dp[i]; 
        if(i == j || isPalindrom(i,j,s)) return dp[i] = 0;
        int minCut = INT_MAX;
        for(int k = i ; k < j ; k++) {
            if(isPalindrom(i,k,s)) {
                int rightCut = frontPartition(k + 1 , j , s , dp) + 1;
                minCut = min(minCut , rightCut);
            }
        }
        return dp[i] = minCut != INT_MAX ? minCut : 0;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return frontPartition(0 , n - 1 , s , dp);
    }
};

/*
Solution Using Tabulation
Time Complexity = O(N^3)
Space Complexity = O(N)
Auxilary Space Complexity = O(1) 
*/
class Solution {
    bool isPalindrom(int i , int  j , string &s ) {
        while(i < j )
            if(s[i++] != s[j--])
                return false;
        return true;
    }

    int tabulation(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n , 0));
        int j = n - 1;
        for(int i = n - 1; i >= 0 ; i--) {
                if(i == j || isPalindrom(i,j,s))
                    dp[i][j] = 0;
                else {
                    int minCut = INT_MAX;
                    for(int k = i ; k < j ; k++) {
                        if(isPalindrom(i,k,s)) {
                            int rightCut = dp[k + 1][j] + 1;
                            minCut = min(minCut , rightCut);
                        }
                    }
                    dp[i][j] = minCut == INT_MAX ? 0 : minCut; 
                } 
        }
        return dp[0][n-1];
    }
public:
    int minCut(string s) {
        return tabulation(s);
    }
};