/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N * M)*/
/*Space Complexity = O(1)*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>sMap(26 ,0 ) , pMap(26 ,0) , ans;
        int n = s.length() , m = p.length();
        if(n < m) return {};
        for(int i = 0 ; i < m ; i++) {
            sMap[s[i] - 'a']++;
            pMap[p[i] - 'a']++;
        }
        
        if(sMap == pMap) ans.push_back(0);

        for(int i = m ; i < n ; i++) {
            sMap[s[i] - 'a']++;
            sMap[s[i - m] - 'a']--;

            if(sMap == pMap) ans.push_back(i - m + 1);
        }
        return ans;

    }
};