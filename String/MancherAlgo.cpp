/**
 * Mancher algorightm to find Palindrom Substring
 * Time Complexity = O(N);
 * Space Complexity = O(N);
 */

class Solution {
public:
    string longestPalindrome(string s) {
        string str = "#";
        string ans;
        for(char c : s) {
            str += c;
            str += "#";
        }
        int n = str.size();
        vector<int>palindromCnt( n  , 0);
        int right = 0 , center = 0;
        int start = 0 , end = 0 , maxLen = 0;
        for(int i = 0 ; i < n ; i++) {
            int mirror = 2 * center - i;
            if (i < right) {
                palindromCnt[i] = min(palindromCnt[mirror] , right -  i);
            }

            int r = i + 1 + palindromCnt[i];
            int left = i - 1 - palindromCnt[i];

            while(r < n && left >= 0
                && str[r] == str[left]) {
                    palindromCnt[i]++;
                    left--;
                    r++;
            }

            if(palindromCnt[i] + i > right) {
                right = palindromCnt[i] + i;
                center = i;
            }

            if( 2 * palindromCnt[i] + 1 > maxLen) {
                maxLen = 2 * palindromCnt[i] + 1;
                start = i - palindromCnt[i];
                end = i + palindromCnt[i] ;
            }
        }

        for(int i = start ; i<= end ; i++) {
            if(str[i] == '#') continue;
            ans += str[i];
        }

        return ans;
    }
};