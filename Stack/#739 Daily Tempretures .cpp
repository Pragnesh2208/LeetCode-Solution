/************************************Optimal solution to find Daily temperatures******/
/************************************Time complexity = O (N) *************************/
/************************************Space Complexity = O (N)*************************/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans;
        int l1 = temperatures.size();
        for(int  i = 0 ; i < l1 ; i++ ) {
            while(!st.empty() && temperatures [ st.top () ] < temperatures[i] ) {
                temperatures[st.top()] = i  - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            temperatures [ st.top ()] = 0;
            st.pop();
        }
        return temperatures;
    }
};