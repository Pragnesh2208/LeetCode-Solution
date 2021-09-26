/******************************Optimal approach To Find minimum in rotate sorted array**********************/
/******************************Time complexity:*************************************************************/
/******************************For average case =  theta of(LOGN) and***************************************/
 /***************************for wrost case O(n)************************************************************/
/******************************Space complexity = O(1)******************************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0 ,right=nums.size()-1;
        while(left<right)
        {
            int mid = left+(right-left)/2;
           if(nums[mid] > nums[right])
           {
               left=mid+1;
           }
            else if( nums[mid] > nums[left])
            {
                right=mid-1;
            }
            else
                right--;
        }
        return nums[left];
    }
};