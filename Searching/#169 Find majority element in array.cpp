/******************************Optimal approach To Find majority element in array*************************/
/*****************************Time complexity = O(N)******************************************************/
/*****************************Space complexity = O(1)*****************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count=0 , ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==nums[ans] || count==0)
            {count++;
                ans=i;}
            else
                count--;
        }
        return nums[ans];
    }
};