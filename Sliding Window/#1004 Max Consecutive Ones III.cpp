/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0 ;
        int chance = k;
        int ans = 0;
        for(int end = 0 ; end < n ; end++) {
            while(nums[end] == 0 && chance == 0){
                if(nums[start++] == 0) chance++;
            }

            if(nums[end] == 0) chance--;

            ans = max(ans , end - start + 1);
        }
        return ans;
    }
};