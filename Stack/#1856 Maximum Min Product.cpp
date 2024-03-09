/*
Optimal Solution of Maximum Min Product
Time Complexity = O(N)
Space Complexity = O(N)
*/
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long ans = 0 , n = nums.size();
        vector<long long>next(n , -1) , prev(n  , -1) , sum (n  , 0);
        stack<long long>st;
        for(int i = n - 1; i >=0 ; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            next[i] =  st.empty() ? -1  : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = 0; i < n  ; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            prev[i] =  st.empty() ? -1 : st.top();
            st.push(i);
            sum[i] = i == 0 ? nums[i] : (nums[i]+ sum[i - 1] );
        }

        for(int i = 0 ; i < n ; i++){
            long long prevIndex = prev[i], nextIndex = next[i];
            long long prevSum , nextSum;
            if(prevIndex == -1) prevSum = 0;
            else prevSum = sum[prevIndex];
            if(nextIndex == -1) nextSum = sum[n - 1];
            else nextSum = sum[nextIndex - 1];
            long long totalSum =  (nextSum - prevSum);
            ans = max(ans , (totalSum  * nums[i] ));
        }
        return ans % 1000000007;
    }
};