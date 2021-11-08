/********************************Optimal approach to Find Minimum Subsequence in Non-Increasing Subsequence********/ 
/********************************Time Complexity  = O (  N LOG N )*************************************************/
/********************************Space Complexity  = O ( N )*******************************************************/
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
       sort(nums.begin() , nums.end() , greater<int>());
        int total = 0;
        int subTotal = 0;
        for(auto i : nums) {
            total += i;
        }
        int pos = 0;
        vector<int>res;
        while(subTotal <= total) {
            subTotal += nums[pos];
            total -= nums[pos];
            res.push_back(nums[pos++]);
        }
        return res;
    }
};