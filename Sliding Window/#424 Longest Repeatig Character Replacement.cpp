/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length() , ans = 0 , maxF = 0;
        vector<int>mp(26 , 0);
        for(int end = 0 , start = 0 ; end < n ; end++){
            maxF = max(maxF , ++mp[s[end] - 'A']);

            while(end - start + 1 - maxF > k) {
                --mp[s[start++] - 'A']; 
            }

            ans = max(ans , end - start + 1 );
        }

        return ans;
    }
};