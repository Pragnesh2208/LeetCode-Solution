//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
/*********
 * Time Complexity is O(N*M)
 * Space Complexity is O(N*M)
 * 
*/

class Solution{   
    
    int memoization(int ind1 ,int ind2 , string &s1 , string &s2  , vector<vector<int>>&dp) {
        if(ind1 == -1 || ind2 == -1) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1] == s2[ind2]) {
            return dp[ind1][ind2] = 1 +  memoization(ind1 - 1  , ind2 - 1 , s1 , s2 , dp);
        }
        
        int dif1 = memoization( ind1 - 1, ind2 , s1 , s2  , dp);
        int dif2 = memoization( ind1 , ind2 - 1 , s1 , s2  , dp);
        return dp[ind1][ind2] =  max(dif1 , dif2) ;
    }
    
public:
    int findMinInsertions(string S){
        // code here 
        int len = S.length() - 1;
        string s1 = S , s2 = "";
        
        for(int i = len ; i >=0 ; i--) 
            s2.push_back(S[i]);
            
        vector<vector<int>>dp(len + 1 , vector<int>(len + 1 , -1));
        return len + 1 - memoization(len ,len , s1 , s2  , dp );
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends