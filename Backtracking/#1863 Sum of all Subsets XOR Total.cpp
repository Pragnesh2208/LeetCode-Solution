/********************************Optimal approach to Sum of all Subsets XOR Total********/ 
/********************************Time Complexity  = O ( 2 ^ N  )*****************************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
public:
    int subset(vector<int>&nums , int sum , int i) {
        if(i == nums.size()) {
            return sum;
        }
        int l = subset(nums , sum  , i+1);
        int r = subset(nums , sum ^ nums[i] , i+1);
        return l+r;
    }
    int subsetXORSum(vector<int>& nums) {
     return subset(nums , 0 , 0);   
    }
};