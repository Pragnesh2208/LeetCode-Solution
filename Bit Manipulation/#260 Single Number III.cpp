/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N)
 * Space Complexity = O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long int xorOfAll = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++) {
            xorOfAll ^= nums[i];
        }

        int rightSetBit = xorOfAll & ~(xorOfAll - 1);
        int num1 = 0 , num2 = 0;

        for(int i = 0 ; i< n ; i++) {
            if(rightSetBit & nums[i]) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }

        return {num1 , num2};
    }
};