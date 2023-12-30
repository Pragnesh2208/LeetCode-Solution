/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int prod = 1;
        int ans = 0;

        for(int end = 0 ; end < n ; end++) {
            while(prod * nums[end] >= k && start < end) {
                prod /= nums[start];
                start++;
            } 

            if(prod * nums[end] < k ) {
                prod *= nums[end];
                ans += (end - start + 1);
            } else {
                start++;
            }
        }
        return ans;
    }
};

/**Clean Code*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int ans = 0;

        for(int end = 0  , start = 0; end < n ; end++) {
            prod *= nums[end];
            while(prod >= k && start <= end) {
                prod /= nums[start++];
            } 
            ans += (end - start + 1);
        }
        return ans;
    }
};