/*
Solution Using Memoization
Time Complexity = O(N^2)
Time Complexity can be calculated as , n number of maximum longest increasing subsequence
example :  1 2 3 4 
we can have subsequence as follows:
4
3 4
2 3 4
1 2 3 4
as there are n subsequence for n length , will take n^2 time

Space Complexity = O(N^2)
Auxilary Complexity = O(N)
*/
class Solution {
    private :
    int len(int ind , int prev , vector<int>&arr , vector<vector<int>>&dp) {
        if(ind == arr.size() ) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int temp = 0;
        temp = len(ind + 1 , prev , arr , dp);
        if(prev == -1 || arr[prev] < arr[ind]) {
            temp = max(
                temp , 
                len(ind + 1 , ind , arr , dp) + 1
            );
        }

        return dp[ind][prev + 1] = temp;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp( n , vector<int>( n  + 1, -1));
        return len(0 , -1 ,nums , dp);
    }
};

/*
Solution Using Tabulation
Time Complexity = O(N^2)
Space Complexity = O(N^2)
*/
class Solution {
    int tabulation(vector<int>&arr) {
        int n = arr.size();
        vector<vector<int>> dp (n + 1 , vector<int>(n + 1 , 0));

        for(int i = n - 1 ; i >= 0 ; i--) {
           for(int prev = i - 1; prev >= -1 ; prev--) {
               int temp = dp[i + 1][prev + 1];
               if(prev == -1 || arr[prev] < arr[i]) {
                   temp = max(temp , dp[i + 1][i + 1] + 1);
               }
               dp[i][prev + 1] = temp; 
           }
        }

        return dp[0][0];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        return tabulation(nums);
    }
};

/*
Solution Using Space Optmization
Time Complexity = O(N^2)
Space Complexity = O(N)
*/
class Solution {
    private :
    int spaceOptimization(vector<int>&arr) {
        int n = arr.size();
        vector<int> next(n + 1 , 0) , curr(n + 1 , 0); 

        for(int i = n - 1 ; i >= 0 ; i--) {
           for(int prev = i - 1; prev >= -1 ; prev--) {
               int temp = curr[prev + 1];
               if(prev == -1 || arr[prev] < arr[i]) {
                   temp = max(temp , curr[i + 1] + 1);
               }
               next[prev + 1] = temp;
           }
           curr = next;
        }

        return curr[0];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        return spaceOptimization(nums);
    }
};


/*
Solution Using Tabulation Variant
Time Complexity = O(N^2)
Space Complexity = O(N^2)
*/

class Solution {
    private :
    int tabulationVariant(vector<int>&arr) {
        int n  = arr.size();
        int maxi = 1;
        vector<int>dp( n + 1 , 1);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ;  j < i ; j++) {
                if(arr[i] > arr[j]) {
                    dp[i] = max(dp[i] , dp[j] + 1);
                    maxi = max(maxi , dp[i]);
                }
            }
        }
        return maxi;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        return tabulationVariant(nums);
    }
};
