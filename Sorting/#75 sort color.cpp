/******************************optimal approach To Sort array of 0s, 1s and 2s**********************/
/******************************Time complexity = O(N)***********************************************/
/******************************Space complexity = O(1)**********************************************/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1,mid=0;
        while(mid<=right)
        {
             /*if nums[mid]==0 then we swap nums[left] with nums [mid] and the array from left to mid  is sorted so we do increment in the value of left and mid */
            if(nums[mid]==0)             
            {
                swap(nums[left++],nums[mid++]);
            }
            /*if nums[mid]==1 then we swap nums[left] with nums [mid] and increment in the value of mid ,here we dont do increment in the value of left as in our answer  nums[left]>0*/
            else if(nums[mid]==1)
            {
                swap(nums[left], nums[mid++]);
            } 
            /*if nums[mid]==2 then we swap nums[right] with nums [mid] and we decrement in the value of right as in our answer nums[right]<2*/
            else
                swap(nums[right--],nums[mid]);
        }
        
    }
};