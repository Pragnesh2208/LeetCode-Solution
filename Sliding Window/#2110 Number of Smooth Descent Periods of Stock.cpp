/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;

        for(int i = 1 , j = 0  ; i < n ; i++) {
            if(nums[i] != nums[i - 1] - 1) j = i;

            ans += i - j + 1; 
        }

        return ans;
    }
};