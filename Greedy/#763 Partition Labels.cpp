/********************************Optimal approach using greedy*********************************/ 
/********************************Time Complexity  = O (N) ***********************************/
/********************************Space Complexity  = O (1) **********************************/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int>freq(26, 0) , curFreq(26 , 0) , ans;
        int last = -1;

        for(int i = 0 ; i < n ; i++) {
            freq[s[i] - 'a']++;
        }

        for(int i = 0 ; i < n ; i++) {
            curFreq[s[i] - 'a']++;
            
            bool getAll = true;
            for(int j = 0 ; j < 26 ; j++) {
                if(curFreq[j] != 0 && freq[j] != curFreq[j]) {
                    getAll = false;
                    break;
                }
            }
            if(getAll) {
                ans.push_back(i - last);
                last = i;

                for(int j = 0 ; j < 26 ; j++) {
                    curFreq[j] = 0;
                }
            }
        }

        return ans;
    }
};