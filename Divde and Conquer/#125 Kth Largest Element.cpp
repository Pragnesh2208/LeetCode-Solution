/************************Optimal solution to find Kth Largest Element in Array Using Divide & Conquer*************************/
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

/************************Optimal solution to find Kth Largest Element in Array Using Heap*************************/
/************************Time Complexity = O(NLogK)**************************************************/
/************************Space Complexity = O(K)*************************************************/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++) {
            minHeap.push(nums[i]);
            if(minHeap.size() > k ) minHeap.pop();
        }

        return minHeap.top();
    }
};