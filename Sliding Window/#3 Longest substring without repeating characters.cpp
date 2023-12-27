/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>bucket(256 , 0);
        int n = s.length();
        int j = 0;
        int ans = 0;
        int i =0;

        while(i < n){

            if(bucket[s[i]] != 0) {
                while(bucket[s[i]] != 0) {
                    bucket[s[j++]]--;
                }
            }

            bucket[s[i]]++;
            ans = max(ans , i++ - j  + 1);

        }
        return ans;
    }
};