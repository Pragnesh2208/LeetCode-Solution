/******************************Optimal approach To Rotate the array by K steps****************************/
/*****************************Time complexity = O(N)******************************************************/
/*****************************Space complexity = O(1)*****************************************************/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      
        int n=nums.size();
         k%=n;
          int i=0,j=n-1;
        if(k==0)
        return;
        while(i<j)
            swap(nums[i++],nums[j--]);
        i=0;j=k-1;
        while(i<j)
            swap(nums[i++],nums[j--]);
        i=k,j=n-1;
        while(i<j)
            swap(nums[i++],nums[j--]);
    
        
    }
};