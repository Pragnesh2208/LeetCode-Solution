/*****************************Brute Force approach To find Product of array except self*******************/
/*****************************Time complexity = O(N)*****************************************************/
/*****************************Space complexity = O(N)***************************************************/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        int n=nums.size();
         vector<int>ans(n);
     vector<int>left(n);
        vector<int>right(n);
        
            left[0]=nums[0];
            right[n-1]=nums[n-1];
       
        for(int i=1;i<n;i++)
           left[i]=nums[i]*left[i-1];
         for(int i=n-2;i>=0;i--)
           right[i]=nums[i]*right[i+1];
         ans[0]=right[1];
        for(int i=1;i<n-1;i++)
        {
            ans[i]=left[i-1]*right[i+1];
        }
        ans[n-1]=left[n-2];
        return ans;
        
    }
};
/******************** Optimal approach To find Product of array except self*******************/
/*******************Time complexity = O(N)****************************************************/
/*******************Space complexity = O(1)***************************************************/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
         int n = arr.size();
    
    vector<int> result(n, 1);
    
    int left = 1, right=1;
    
    for(int i=0;i<n;i++){
        result[i] *= left;
        left *= arr[i];
        
        result[n-1-i] *= right;
        right *= arr[n-1-i];
    } 
    return result;
    }
};