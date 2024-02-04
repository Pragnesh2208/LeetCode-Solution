/* Optimal Solution 
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() , left = 0 ,right = 0 , ans = 0;
        while(right < n - 1) {
            int maxDist = 0;
            int tempLeft = left , tempRight =  right;
            for(int i = left ; i <= right ; i++) {
                if( i + nums[i] >= maxDist){
                    maxDist = i + nums[i];
                    tempLeft = i + 1;
                    tempRight = i + nums[i];
                }
            }

            left = tempLeft ;
            right =  tempRight;
            ans++;
        }

        return ans;
    }
};