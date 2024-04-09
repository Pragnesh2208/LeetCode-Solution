/********************************Optimal approach using greedy*********************************/ 
/********************************Time Complexity  = O (N) ***********************************/
/********************************Space Complexity  = O (1) **********************************/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n < k) return false;
        
        vector<int>freq(26 , 0);
        int odd = 0;

        for(int i = 0 ; i < n ; i++) {
            freq[s[i] - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++) {
            odd += (freq[i] % 2);
        }

        return odd <= k;
    }
};