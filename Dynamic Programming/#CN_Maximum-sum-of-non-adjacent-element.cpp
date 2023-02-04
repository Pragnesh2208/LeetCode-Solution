/****************Find Maximum sum of non-adjacent element using recursion*******************/
/****************Time Complexity = O(3 ^ n)*************************************/
/****************Space Complexity = O(N)************************************/
#include <bits/stdc++.h> 
using namespace std;

void recursion(int ind , vector<int>&nums , int sum , int &ans) {  
    sum += nums[ind];
    ans = max(ans , sum);
    for(int i = 2 ; (i + ind) < nums.size() ; i++) {
        recursion(i+ind , nums , sum , ans);
    }
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int ans = INT_MIN;
    int n = nums.size() ;

    for(int i = 0 ; i < n; i++)
        recursion(i , nums , 0 , ans);

    return ans;
}

/****************Find Maximum sum of non-adjacent element using Backtracking*******************/
/****************Time Complexity = O(2 ^ n)*************************************/
/****************Space Complexity = O(N)************************************/

#include <bits/stdc++.h> 
using namespace std;

int backtracking(int i , vector<int>&nums) {
    if(i <= 0) return i == 0 ? nums[0] : 0;
    int pick = nums[i] + backtracking( i - 2 , nums);
    int non-pick = backtracking(i-1 , nums);
    return max(pick  , non-pick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size() - 1;
  return backtracking( n , nums);
}


/****************Find Maximum sum of non-adjacent element using Memoization*******************/
/****************Time Complexity = O(n)*************************************/
/****************Space Complexity = O(N)************************************/

#include <bits/stdc++.h> 
using namespace std;

int memoization(int i, vector<int>&nums , vector<int>&dp) {
   
   if(i <= 0) i == 0 ? dp[0] = nums[0] : 0;
    if(dp[i] != -1) return dp[i];

   int pick = nums[i] + memoization(i - 2 , nums , dp);
   int non-pick = memoization(i - 1 , nums , dp);
   return dp[i] = max(pick , non-pick);
 }


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int ans = INT_MIN;
    int n = nums.size() ;
    vector<int>dp(n , -1);
    return memoization(n-1 , nums , dp);  
}


/****************Find Maximum sum of non-adjacent element using Tabulation*******************/
/****************Time Complexity = O(n)*************************************/
/****************Space Complexity = O(N)************************************/
#include <bits/stdc++.h> 
using namespace std;

int tabulation(vector<int>&nums ) {
   int n = nums.size();
   vector<int>dp(n , 0);

   dp[0] = nums[0];
   for(int i = 1; i < n ; i++) {
    if(i > 1)
    dp[i] = max(dp[i-1] , nums[i] +dp[i-2]);
    else dp[i] = max(nums[i] , dp[i-1]);
   }
   return dp[n-1];
 }

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return tabulation(nums);
}

/****************Find Maximum sum of non-adjacent element using Space Optimization*******************/
/****************Time Complexity = O(n)**************************************************************/
/****************Space Complexity = O(N)*************************************************************/

#include <bits/stdc++.h> 
using namespace std;

int spaceOptimization(vector<int>&nums ) {  
    int prev1 = nums[0] , prev2;
    int n = nums.size();

    for(int  i = 1 ; i < n ; i++) {
        if(i == 1) {
           prev2 = prev1;
            prev1 = max(prev1 , nums[i]);
        }
        else {
            int temp = prev1;
            prev1 = max(prev1 , nums[i] + prev2);
            prev2 = temp;
        }
         
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return spaceOptimization(nums);
}

