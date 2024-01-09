/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0 , n = nums.size();
        int k = 1 , j = 0;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 0) k--;
            while(k < 0 ) {
                if(nums[j] == 0) {
                    k++;   
                }
                j++;
            }
            ans = max(ans , i - j + 1);
        }

        return ans - 1;
    }
};