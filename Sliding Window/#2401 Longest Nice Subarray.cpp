/*Solution Using Better Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        vector<int>bits(32 , 0);

        for(int i = 0 , j = 0 ; i < n ; i++) {
            for(int k = 0 ; k < 32 ; k++) {
                if((1 << k ) & nums[i]) bits[k]++;
            }

            for(int  k = 0 ; k <  32 ; k++) {
                while(bits[k] > 1) {
                    
                        for(int l = 0 ; l < 32 ; l++) {
                            if((1 << l) & nums[j]) {
                                bits[l]--;
                            }
                        }
                    j++;
                }
            }
            ans = max(ans , i - j + 1);
        }
        return ans;
    }
};

/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        long long xp = 0;

        for(int i = 0 , j = 0 ; i < n ; i++) {
            while(xp & nums[i]) {
                xp ^= nums[j++];
            }

            xp ^= nums[i];

            ans = max(ans , i - j + 1);
        }
        return ans;
    }
};