/******************************Optimal approach To Find minimum in rotate sorted array**********************/
/******************************Time complexity = O(LOGN)***********************************************/
/******************************Space complexity = O(1)*************************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,ans=INT_MAX;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid] < nums[right])
                {
                    ans=min(ans,nums[mid]);
                right=mid-1;
                }
            else
                {
               ans=min(ans,nums[mid]);
               left=mid+1;
                }
        }
        return ans;
    }
};