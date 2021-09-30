/******************************optimal approach ****************************************************/
/******************************Time complexity = O(N)***********************************************/
/******************************Space complexity = O(1)**********************************************/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        int Max=INT_MIN;
        for(int i=0;i<n-2;i++)
        {
            Max=max(Max,nums[i]);
            if(Max>nums[i+2])
                return false;
        }
        return true;
    }
};