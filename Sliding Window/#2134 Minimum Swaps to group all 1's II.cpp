/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        long long int oc = 0 , n = nums.size() , ans = INT_MAX , zc = 0;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 1) oc++;
        }

        for(int i = 0 ; i < oc ; i++) {
            if(nums[i] == 0) zc++;
        }
        ans = min(ans , zc);

        for(int j = oc ; j < (oc + n) ;j++) {

            int i = (j % n);
            if(nums[j - oc] == 0)zc--;
            if(nums[i] == 0) zc++;
            ans = min(ans , zc);
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};