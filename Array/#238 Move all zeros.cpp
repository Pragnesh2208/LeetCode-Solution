/******************************Optimal approach To Move all zeros  in array*******************************/
/*****************************Time complexity = O(N)******************************************************/
/*****************************Space complexity = O(1)*****************************************************/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0 ,pos =0;
        while(pos!=nums.size())
        {
          if(nums[pos]!=0)
          {
              swap(nums[pos],nums[start]);
              start++;
          }
                pos++;  
        }
    }
};