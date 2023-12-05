/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N)
 * Space Complexity = O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>bitmask(32,0);
        for(int i = 0 ; i < n ; i++) {
           for(int j = 0 ; j < 32 ; j++) {
               if((1 << j) & nums[i]) {
                   bitmask[j]++;
               }
           }
        }
        int ans = 0;
        for(int i = 0 ; i < 32 ;i++) {
            if(bitmask[i] % 3 != 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};