/************************************Optimal approach to find Number of Visible People in a Queue****/
/************************************Time complexity = O( N)*****************************************/
/************************************Space Complexity = O ( N )**************************************/
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        stack<int>st;
        int n = heights.size();
        vector<int>ans(n);

        for(int i = n -1 ; i >= 0 ; i-- ) {

            while(!st.empty() && heights[st.top()] <= heights[i] ) {

                st.pop();
                ans[i]++;
            }
            if(!st.empty())
                ans[i]++;
                
            st.push(i);
        }
        return ans;
    }
};