/*
Maximum Rectangle using stack
Time Complexity = O(M * N)
Space Complexity = O(M)
*/
class Solution {
    int maximumAreaOfHistogram(vector<int>&nums) {
        int ans = 0 , n = nums.size();
        vector<int>next(n , 0) , prev(n , 0);
        stack<int>st;
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1 ; i >=0 ; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            next[i] = st.empty() ? n   : st.top();
            st.push(i);
        }

        for(int i = 0 ; i < n ; i++){
            int nextIndex = next[i] - 1 , prevIndex = prev[i] + 1;
            int area = ((nextIndex - prevIndex + 1) * nums[i]);
            ans = max(ans , area);
           
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() , ans = 0;
        vector<int>height(m , 0);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(matrix[i][j] == '0') height[j] = 0;
                else height[j]++;
            }

            ans = max(ans , maximumAreaOfHistogram(height));
        }

        return ans;
    }
};