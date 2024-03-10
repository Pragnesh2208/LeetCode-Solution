/*
Optimal Solution to create a smallest number from DI string
Time Complexity = O(N)
Space Complexity = O(N)
*/
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int>st;
        int count = 1;
        string ans = "";

        for(int i = 0 ; i < n ; i++) {
            st.push(count++);

            while(pattern[i] == 'I' && !st.empty()) {
                ans += (st.top() + '0');
                st.pop();
            }
        }
        st.push(count);
        while(!st.empty()) {
             ans += (st.top() + '0');
                st.pop();
        }
        return ans;
    }
};s