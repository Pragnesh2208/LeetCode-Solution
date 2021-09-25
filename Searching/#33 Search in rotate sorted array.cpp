/******************************Optimal approach To search in rotate sorted array**********************/
/******************************Time complexity = O(LOGN)***********************************************/
/******************************Space complexity = O(1)*************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[start] <=nums[mid])
            {
                if(target < nums[mid] && target >= nums[start])
                    end=mid-1;
                else
                    start=mid+1;
            }
            else if(nums[mid]<=nums[end])
            {
                if(nums[mid] < target && nums[end]>=target)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return -1;
        
    }
};