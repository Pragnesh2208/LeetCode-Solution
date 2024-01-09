/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0 , ans = 0 , n = nums.size();
        int j = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];

            while(sum * (i - j + 1)  >= k) {
                sum -= nums[j++];
            }

                ans += (i - j + 1);
            
        }
        return ans;
    }
};