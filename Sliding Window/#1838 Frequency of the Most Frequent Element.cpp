/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(NLOGN)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size() , ans = 1;
        long long nk = k ;
        sort(nums.begin() , nums.end());

        for(int i = 1  , j = 0; i < n ; i++) {
            long long int dif = nums[i] - nums[i - 1];
            nk -= (dif * (i - j));

            while(nk < 0){
                nk += (nums[i] - nums[j++]);
            }
            ans = max(ans , (i - j + 1));
        }

        return ans;
    }
};