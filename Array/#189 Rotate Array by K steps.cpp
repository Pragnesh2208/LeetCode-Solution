/******************************Optimal approach To Rotate the array by K steps****************************/
/*****************************Time complexity = O(N)******************************************************/
/*****************************Space complexity = O(1)*****************************************************/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums , 0 , n-1);
        reverse(nums , 0 , k-1);
        reverse(nums , k ,n-1);
    }
    void reverse(vector<int>&nums , int start , int end)
    {
        while(start < end)
        {
            swap(nums[start++] ,nums[end--]);
        }
    }
};