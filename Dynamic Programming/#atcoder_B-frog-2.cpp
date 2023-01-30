/****************Solution for Frog-2 jump using Tabulation*******************/
/****************Time Complexity = O(N*K)*************************************/
/****************Space Complexity = O(N)************************************/

#include<bits/stdc++.h>
using namespace std;
int main() {

  int n , k;
  cin>>n>>k;
  vector<int>arr(n , 0);
  vector<int>dp(n ,INT_MAX);
  for(int i = 0 ; i < n ; i++) cin>>arr[i];
  dp[0] = 0;
  for(int i = 1 ; i < n ; i++) {
  	for(int j = i ; j >= i - k && j >=0 ; j--) {
    	dp[i] = min(dp[i] , dp[j]+ abs(arr[i] - arr[j]));
    }
  }
  cout<<dp[n - 1]<<endl;
}


/****************Space Optimized Solution for Frog-2 jump ********************/
/****************Time Complexity = O(N*K)*************************************/
/****************Space Complexity = O(K)************************************/

#include<bits/stdc++.h>
using namespace std;
int main() {

  int n , k;
  cin>>n>>k;
  vector<int>arr(n , 0);
  vector<int>dp(k + 1 ,INT_MAX);
  for(int i = 0 ; i < n ; i++) cin>>arr[i];
  dp[0] = 0;
  for(int i = 1 ; i < n ; i++) {
    dp[i  % ( k + 1 )] = INT_MAX;
  	for(int j = i ; j >= i - k && j >=0 ; j--) {
    	dp[i % ( k + 1 )] = min(dp[i % ( k + 1)] , dp[j % ( k + 1)]+ abs(arr[i] - arr[j]));
    }
  }
  cout<<dp[(n - 1) % ( k + 1 )]<<endl;
}