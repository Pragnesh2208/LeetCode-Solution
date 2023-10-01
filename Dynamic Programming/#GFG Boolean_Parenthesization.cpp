/*
Recursion Solution
Time Complexity = Exponential
Space Complexity = O(1)
Auxilary Space Complexity = O(N)
*/
class Solution{
    int mcm(int i , int j ,bool isTrue ,string &s ) {
        if(i > j ) return 0;
        if(i == j) {
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        int ways = 0;
        
        for(int k = i + 1 ; k < j ; k+=2) {
            int leftFalse = mcm(i , k - 1 , false , s);
            int leftTrue = mcm(i, k - 1 , true , s);
            int rightFalse = mcm(k + 1 , j , false , s);
            int rightTrue = mcm(k + 1 , j , true , s);
            
            if(s[k]=='&') {
                if(isTrue) {
                    ways += (leftTrue * rightTrue);
                } else ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse); 
            } else if(s[k] == '|') {
                if(isTrue) {
                    ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightTrue);
                } else ways += (leftFalse * rightFalse);
            } else if(s[k] == ' ^') {
                if(isTrue) {
                    ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
                } else {
                    ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
                }
            }
        }
        return ways;
    }
public:
    int countWays(int N, string S){
        // code here
        return mcm(0 , N-1 , true , S);
    }
};

/*
Memoization Solution
Time Complexity = O(N^3)
Space Complexity = O(N^2)
Auxilary Space Complexity = O(N)
*/
class Solution{
    int mcm(int i , int j ,bool isTrue ,string &s  , vector<vector<vector<int>>> &dp) {
        if(i > j ) return 0;
        
        if(i == j) {
            if(isTrue) return dp[i][j][isTrue] = s[i] == 'T';
            else return dp[i][j][isTrue]  = s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != - 1) return dp[i][j][isTrue];
        
        long long ways = 0;
        
        for(int k = i + 1 ; k < j ; k+=2) {
            int leftFalse = mcm(i , k - 1 , false , s , dp);
            int leftTrue = mcm(i, k - 1 , true , s , dp);
            int rightFalse = mcm(k + 1 , j , false , s , dp);
            int rightTrue = mcm(k + 1 , j , true , s , dp);
            int ltrt = (leftTrue * rightTrue) % 1003;
            int ltrf = (leftTrue * rightFalse) % 1003;
            int lfrt = (leftFalse * rightTrue) % 1003;
            int lfrf = (leftFalse * rightFalse) % 1003;
            
            if(s[k]=='&') {
                if(isTrue) {
                    ways = (ways + ltrt) % 1003;
                } else ways =(ways +  ltrf + lfrt + lfrf) % 1003 ; 
            } else if(s[k] == '|') {
                if(isTrue) {
                    ways = (ways + lfrt + ltrf + ltrt) % 1003;
                } else ways =(ways + lfrf) % 1003;
            } else if(s[k] == '^') {
                if(isTrue) {
                    ways = (ways + ltrf + lfrt) % 1003;
                } else {
                    ways = (ways + ltrt + lfrf)% 1003;
                }
            }
        }
        return dp[i][j][isTrue]  = ways ;
    }
public:
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N , vector<vector<int>>(N , vector<int>(2, -1)));
        return mcm(0 , N-1 , true , S , dp);
    }
};

/*
Tabulation Solution
Time Complexity = O(N^3)
Space Complexity = O(N^2)
*/

class Solution{
    int tabulation(int N , string &s) {
        vector<vector<vector<int>>> dp(N , vector<vector<int>>(N , vector<int>(2, 0)));
        for(int i = 0 ; i < N ; i++) {
            dp[i][i][1] = s[i] == 'T';
            dp[i][i][0] = s[i] == 'F';
        }
        
        for(int i = N - 1 ; i >= 0 ; i--) {
            for(int j = i ; j < N ; j++) {
                for(int isTrue = 0 ; isTrue <= 1 ; isTrue++) {
                    int ways = 0 ;
                    for(int k = i + 1 ; k < j ; k+=2) {
                        int leftFalse = dp[i][k - 1][0];
                        int leftTrue = dp[i][k - 1][1];
                        int rightFalse = dp[k + 1][j][0];
                        int rightTrue = dp[k + 1][j][1];
                        int ltrt = (leftTrue * rightTrue) % 1003;
                        int ltrf = (leftTrue * rightFalse) % 1003;
                        int lfrt = (leftFalse * rightTrue) % 1003;
                        int lfrf = (leftFalse * rightFalse) % 1003;
                        
                        if(s[k]=='&') {
                            if(isTrue) {
                                ways = (ways + ltrt) % 1003;
                            } else ways =(ways +  ltrf + lfrt + lfrf) % 1003 ; 
                        } else if(s[k] == '|') {
                            if(isTrue) {
                                ways = (ways + lfrt + ltrf + ltrt) % 1003;
                            } else ways =(ways + lfrf) % 1003;
                        } else if(s[k] == '^') {
                            if(isTrue) {
                                ways = (ways + ltrf + lfrt) % 1003;
                            } else {
                                ways = (ways + ltrt + lfrf)% 1003;
                            }
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }
        return dp[0][N-1][1];
    }
public:
    int countWays(int N, string S){
        tabulation(N , S);
        // code here
    }
};

