/********************************Optimal approach using greedy*********************************/ 
/********************************Time Complexity  = O (N) ***********************************/
/********************************Space Complexity  = O (1) **********************************/

class Solution {
public:
    string strWithout3a3b(int a, int b) {

        string ans;

       while(a + b > 0) {
            if(a >= b  && ( ans.size() < 2 || ans[ans.size() - 2] != 'a' || ans.back() != 'a')) {
                ans += "a";
                a--;
            } else if(b > 0 && ( ans.size() < 2 || ans[ans.size() - 2] != 'b' || ans.back() != 'b')) {
                ans += "b";
                b--;
            }

            if(b >= a && b > 0&& ( ans.size() < 2 || ans[ans.size() - 2] != 'b' || ans.back() != 'b')) {
                ans += "b";
                b--;
            } else if(a > 0 &&( ans.size() < 2 || ans[ans.size() - 2] != 'a' || ans.back() != 'a')) {
                ans += "a";
                a--;
            }
       }

        return ans;
    }
};