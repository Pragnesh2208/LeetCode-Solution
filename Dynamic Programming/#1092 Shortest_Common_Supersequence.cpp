/* Clean Code
Time Complexity = O(N*M)
Space Complexity = O(N*M)
*/
class Solution {
    int lcs(int ind1 , int ind2 , string &s1 , string &s2 , vector<vector<int>>&dp) {
        int n = s1.length();
        int m = s2.length();
        if(ind1 == n || ind2 == m) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] =  lcs(ind1 + 1 , ind2 + 1 , s1 , s2 , dp) + 1;
        return dp[ind1][ind2] =  max(lcs(ind1 + 1 , ind2 , s1 , s2 , dp) , lcs(ind1 , ind2 + 1 , s1 , s2 , dp)); 
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        vector<vector<int>>dp(n , vector<int>(m , -1));
        lcs(0 , 0 , str1 , str2 , dp);
        int ind1 = 0 , ind2 = 0;
        string ans = "";
        while(ind1 < n && ind2 < m) {
            if(str1[ind1] == str2[ind2]) {
                ans.push_back(str1[ind1]);
                ind1++;
                ind2++;
            } else {
                if(ind1 + 1 == n) {
                    ans.push_back(str2[ind2++]);
                } else if(ind2 + 1 == m) {
                    ans.push_back(str1[ind1++]);
                }
                else if( dp[ind1 + 1][ind2] > dp[ind1][ind2 + 1]) {
                    ans.push_back(str1[ind1++]);
                }else {
                    ans.push_back(str2[ind2++]);
                }
            }
        }

        while(ind1 < n) {
            ans.push_back(str1[ind1++]);
        }
        
        while(ind2 < m) {
            ans.push_back(str2[ind2++]);
        }

        return ans;
    }
};

/*
Time Complexity = O(N*M)
Space Complexity = O(N*M)
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size() , m  = str2.size();

        vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        string lcs = "";
        int i = n , j = m;
        while(i >= 1 && j >= 1) {
           
            if(str1[i - 1] == str2[j - 1]) {
                lcs += str1[i-1];
                
                if(dp[i][j] == 0) {
                    i--;
                } else {
                    i--;
                    j--;
                }
            } else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    lcs += str1[i - 1];
                    i--;
                } else{
                    lcs += str2[j - 1];
                    j--;
                }
            }
        }

        while(i >= 1) {
            lcs += str1[i-1];
            i--;
        }

        while(j >= 1) {
            lcs += str2[j-1];
            j--;
        }
        i = 0 , j = lcs.length() -1;
        while(i < j) swap(lcs[i++] , lcs[j--]);
        return lcs;
    }
};