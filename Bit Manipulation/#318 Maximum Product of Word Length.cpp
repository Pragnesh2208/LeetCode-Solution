/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N ^ 2)
 * Space Complexity = O(N)
 * 
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0 ;
        int n = words.size();
        vector<int>commonLetter(n , 0);
        for(int i = 0 ; i < n ; i++ ){
            int m = words[i].length();
            for(int j = 0 ; j < m ; j++) {
                commonLetter[i] |= ( 1 << (words[i][j] - 'a'));
            }

            for(int j = 0 ; j < i ; j++) {
                if(!(commonLetter[i] & commonLetter[j])) {
                    int m = words[i].size() * words[j].size();
                    ans = max(ans , m);
                }
            }
        }

        return ans;
    }
};