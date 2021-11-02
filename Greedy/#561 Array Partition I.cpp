/********************************Optimal approach to Find Array Partition 1********************/ 
/********************************Time Complexity  = O ( N ) ***********************************************************/
/********************************Space Complexity  = O ( 1 ) **********************************************************/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans = 0 ;
        int n = nums.size();
        for(int i = 0 ; i < n ; i = i + 2) {
            ans += nums [ i];
        }
        return ans;
    }
};