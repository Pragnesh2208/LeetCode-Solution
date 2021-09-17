 /******************************Optimal approach to find target in sorted array***************/
/*******************************Time complexity = O(LOGN) Big o of log N***********************************/
/*******************************Space complexity = O(1)*******************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0 ,high=n-1;
        while(low<=high)
        {
           int mid =low +(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid] < target)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};