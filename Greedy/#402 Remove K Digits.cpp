/* Optimal Solution
Time Complexity = O(N)
Space Complexity = O(N)
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        string ans = "";
        int index = 0;

        for(int i = 0 ; i < n ; i++) {
            while(st.size() > 0 && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }

            if(st.size() == 0 ) {
                if(num[i] != '0') st.push(num[i]); 
            } 
            else {
                st.push(num[i]);
            }
        }

        while(k > 0 && st.size() > 0) {
            st.pop();
            k--;
        }

        while(st.size() > 0) {
            ans += (st.top())  ;
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans.size() == 0 ? "0" : ans;
    }
};