/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int ans = 0;
        int j = 0;
        int cost = 0;
        for(int i = 0 ; i < n ; i++) {
            while(cost+ abs(s[i] - t[i]) > maxCost) {
                cost -= abs(s[j] - t[j]);
                j++;
            }
            cost += abs(s[i] - t[i]);
            ans = max(ans , ( i - j + 1));
        }

        return ans;
    }
};