/********************************Optimal approach to usign greedy********/ 
/********************************Time Complexity  = O (N)*****************************/
/********************************Space Complexity  = O (1)******************************/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int count = 0;
        int openBracket= 0;

        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '(') openBracket++;
            else {
                if(openBracket > 0) openBracket--;
                else count++;
            }
        }

        return count + openBracket;
    }
};