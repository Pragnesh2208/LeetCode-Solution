/****************Solution of Subset Sum Equal to k using Backtracking****************/
/****************Time Complexity = O( 2 ^ N)********************************/
/****************Space Complexity = O(N)************************************/
#include <bits/stdc++.h> 
using namespace std;
bool helper(int ind , int target  , vector<int>&arr ){ 
   
    if(target == 0) return true;
     if(ind < 0) return false;

    bool take = helper(ind - 1 , target , arr );
    if(target < arr[ind]) return take;
    bool notTake = helper(ind - 1 , target - arr[ind] , arr );
    return (take || notTake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return helper(n-1 , k , arr );
}

/****************Solution of Subset Sum Equal to k using Memoization****************/
/****************Time Complexity = O( N * K)********************************/
/****************Space Complexity = O(N * K)************************************/

#include <bits/stdc++.h> 
using namespace std;
bool helper(int ind , int target  , vector<int>&arr , vector<vector<int>>&dp){ 
   
    if(target == 0) return true;
     if(ind < 0) return false;
    if(dp[ind][target] != -1 ) return dp[ind][target];

    bool take = helper(ind - 1 , target , arr , dp);
    if(target < arr[ind]) return dp[ind][target] = take;
    bool notTake = helper(ind - 1 , target - arr[ind] , arr , dp);
    return dp[ind][target] = (take || notTake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp (n , vector<int>(k+1 , -1));
    return helper(n-1 , k , arr , dp);
}

/****************Solution of Subset Sum Equal to k using Tabulation****************/
/****************Time Complexity = O( N * K)********************************/
/****************Space Complexity = O(N * K)************************************/
#include <bits/stdc++.h> 
using namespace std;
bool helper(int ind , int target  , vector<int>&arr , vector<vector<bool>>&dp){ 
   
   for(int i = 0 ; i <=ind ; i++) dp[i][0] = true;
   dp[0][arr[0]] = true;
   for(int i = 1 ; i <= ind ; i++) {
       for(int j = 1 ; j <= target ; j++) {
          
           bool take = false , notTake = false;
           if(arr[i] <= j)
            take = dp[i-1][j-arr[i]];
           notTake = dp[i-1][j];
           
           dp[i][j] = take | notTake;
       }
   }
   return dp[ind][target];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp (n , vector<bool>(k+1 ,false));
    return helper(n-1 , k , arr , dp);
}


/****************Solution of Subset Sum Equal to k using Space Optimization****************/
/****************Time Complexity = O( N * K)********************************/
/****************Space Complexity = O(K)************************************/
#include <bits/stdc++.h> 
using namespace std;
bool helper(int ind , int target  , vector<int>&arr){ 
    vector<bool>prev(target+1 ,false);
    prev[0] = true;
    prev[arr[0]]=true;
    for(int i = 1 ; i <= ind ; i++) {
          vector<bool>cur(target+1 ,false);
          cur[0] = true;
       for(int j = 1 ; j <= target ; j++) {
           bool take = false , notTake = false;
           if(arr[i] <= j)
            take = prev[j-arr[i]];
           notTake = prev[j];
           cur[j] = take | notTake;
        }
        prev = cur;
    }
   return prev[target];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
  
    return helper(n-1 , k , arr );
}