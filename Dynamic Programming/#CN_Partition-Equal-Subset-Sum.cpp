/****************Solution of Partition Equal Subset Sum using Backracking****************/
/****************Time Complexity = O( 2 ^ N)********************************/
/****************Space Complexity = O(N)************************************/
bool helper(int ind  , long long int sum ,vector<int> &arr) {
	if(sum == 0) return true;
	if(ind < 0) return false;
	bool take = false , notTake = false;
	
	if(sum >= arr[ind])
	take = helper(ind - 1, + sum - arr[ind] , arr );
	notTake = helper(ind - 1, sum, arr );
	return take | notTake;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	long long int target = 0;
	for(int i = 0 ; i < n ; i++) target +=arr[i];
	if(target % 2 !=0 )return false;
	target /= 2; 
	return helper(n - 1 ,target , arr );
}

/****************Solution of Partition Equal Subset Sum using Memoization****************/
/****************Time Complexity = O( target * N)********************************/
/****************Space Complexity = O( target * N)************************************/
bool helper(int ind  , long long int sum ,vector<int> &arr , vector<vector<int>>&dp) {
	if(sum == 0) return true;
	if(ind < 0) return false;
	bool take = false , notTake = false;
	if(dp[ind][sum] != -1) return dp[ind][sum];
	if(sum >= arr[ind])
	take = helper(ind - 1, + sum - arr[ind] , arr , dp);
	notTake = helper(ind - 1, sum, arr , dp);
	return dp[ind][sum] = take | notTake;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	long long int target = 0;
	for(int i = 0 ; i < n ; i++) target +=arr[i];
	if(target % 2 !=0 )return false;
	target /= 2; 
	vector<vector<int>>dp(n , vector<int>(target + 1 , -1));
	return helper(n - 1 ,target , arr , dp);
}

/****************Solution of Partition Equal Subset Sum using Tabulation****************/
/****************Time Complexity = O( target * N)********************************/
/****************Space Complexity = O( target * N)************************************/
bool helper(int ind  , long long int target ,vector<int> &arr) {
	vector<vector<bool>>dp(ind+1 , vector<bool>(target + 1 , false));
	for(int i = 0 ; i <= ind ; i++) dp[i][0] = true;
	dp[0][arr[0]] = true;
	for(int i = 1 ; i <= ind ; i++) {
		for(int j = 1 ; j <= target ; j++) {
			bool take = false , notTake = false;	
			if(j >= arr[i])
			take = dp[i - 1][j - arr[i]];
			notTake = dp[i- 1][j];
			dp[i][j] = take | notTake;	
		}
	}
	return dp[ind][target];
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	long long int target = 0;
	for(int i = 0 ; i < n ; i++) target +=arr[i];
	if(target % 2 !=0 ) return false;
	target /= 2; 
	
	return helper(n - 1 ,target , arr);
}


/****************Solution of Partition Equal Subset Sum using Space Optimization****************/
/****************Time Complexity = O( target * N)********************************/
/****************Space Complexity = O( target )************************************/
bool helper(int ind  , long long int target ,vector<int> &arr) {
	vector<bool>prev(target + 1 , false);
	prev[0] = true;
	if(target >= arr[0])
	prev[arr[0]] = true;
	for(int i = 1 ; i <= ind ; i++) {
		vector<bool>cur(target + 1 , false);
		cur[0] = true;
		for(int j = 1 ; j <= target ; j++) {
			bool take = false , notTake = false;	
			if(j >= arr[i])
			take = prev[j - arr[i]];
			notTake = prev[j];
			cur[j] = take | notTake;	
		}
		prev = cur;
	}
	return prev[target];
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	long long int target = 0;
	for(int i = 0 ; i < n ; i++) target +=arr[i];
	if(target % 2 !=0 ) return false;
	target /= 2; 
	return helper(n - 1 ,target , arr);
}
