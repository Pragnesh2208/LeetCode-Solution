/************************Optimal solution to find Kth Largest Element in Array*************************/
/************************Time Complexity = Theta(N) and O(N^2)**************************************************/
/************************Space Complexity = O(1)*************************************************/
/****************************QuickSelect algorithm using lomuto partition*******************/
/**************************Reference video is back 2 back swe ***************************/
class Solution {
    private:
    int quickSelect(vector<int>&nums , int low , int high , int k) {
        int j = low;
        int pivot = high;
        for(int i= low ; i <= high ; i++) 
            if(nums[i]<nums[pivot]) 
                swap(nums[i],nums[j++]);
        swap(nums[j],nums[pivot]);

        int count = high - j  + 1;
        if(k == count) return nums[j];
        else if( count > k) return quickSelect(nums , j + 1 , high , k );
        else return quickSelect(nums , low , j - 1 , k - count);

    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0, nums.size() - 1,k);
    }
};