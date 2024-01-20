/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
    int atMostKOdd(vector<int>&nums , int k  ) {
        int n = nums.size() , ans = 0;
        long long int count = 0;

        for(int i = 0  , j = 0; i < n ; i++) {
            if(nums[i] & 1) count++;

            while( count > k) {  
                if(nums[j++] & 1) count--;
            }
            ans+=(i- j + 1);
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atMostKOdd(nums , k ) - atMostKOdd(nums , k -1);
    }
};