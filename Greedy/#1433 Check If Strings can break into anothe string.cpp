/********************************Optimal approach to Using Greedy*****/
/********************************Time Complexity  = O (NLOGN)*********/
/********************************Space Complexity  = O (1)************/
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.length();
        sort(s1.begin() , s1.end());
        sort(s2.begin() , s2.end());
        int flag = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s1[i] > s2[i]) {
                if(flag == 2) return false;
                flag = 1;
            } else if(s1[i] < s2[i]) {
                if(flag == 1) return false;
                flag = 2;
            }
        }
        return true;
    }
};