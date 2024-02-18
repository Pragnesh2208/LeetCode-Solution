/************************************Optimal approach to find 132 Pattern******/
/************************************Time complexity = O( N) *****************/
/************************************Space Complexity = O ( N )************************/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        bool ans = false;
        int n = nums.size();
        int num3 = INT_MIN;
        stack<int>st;

        for(int i = n - 1 ; i >= 0  ; i--){
            if(nums[i] < num3) return true;

            while(!st.empty() && st.top() < nums[i]) {
                num3 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};