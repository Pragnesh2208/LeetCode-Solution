/*
Time Complexity = O(N ^ 2)
Space Complexity = O(N)
Using Tabulation
*/
class Solution {
  public:

    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
      int ans = 0;
      vector<int>incr(n  , 1) , decr( n , 1);
      
      for(int i = 0 ; i < n ; i++) {
          for(int prev = 0 ; prev < i ; prev++) {
              if(nums[prev] < nums[i] && incr[i] < incr[prev] + 1) incr[i] = incr[prev] + 1;
          }
      }
      for(int i =  n -1 ; i >=0 ; i--) {
          for(int prev =  n -1 ; prev > i ; prev--) {
              if(nums[prev] < nums[i] && decr[i] < decr[prev] + 1) decr[i] = decr[prev] + 1;
          }
      }
        
        for(int i = 0 ; i < n ; i++) {
            if(incr[i] > 1 && decr[i] > 1)
            ans = max(ans ,  incr[i] + decr[i] - 1);
        }
        
        return ans;
    }
};