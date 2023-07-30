/*
Edge cases : 
aaa
aa

equal
equal

*/

/*
Time Complexity = O(m*n)
Space Complexity = O(m*n)
*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void tabulation(string s1 , string s2) {
	int n = s1.size() , m = s2.size();
	string str = "";
	vector<vector<int>>dp(n + 1, vector<int>(m  + 1, 0));
	for(int i = 0 ; i <= n ; i++)  {
		for(int j = 0 ; j <= m ; j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}
		}
	}
	int i = n , j = m;
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]) {
			str.push_back(s1[i-1]);
			i--;
			j--;
		} else {
			if(dp[i-1][j] > dp[i][j-1]) {
				i--;
			} else j--;
		}
	}
	i = 0 , j = str.size() - 1;
	while(i < j) {
		swap(str[i++],str[j--]);		
	}
	cout<<str<<endl;
}

int main() {
	// Your code goes here;
	int t;
	cin>>t;
	while(t--) {
		string s1 , s2 ; 
	cin>>s1>>s2;
	
	tabulation(s1 , s2);
	
	}
		return 0;
}