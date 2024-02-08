/************************************Optimal approach to find next greater element******/
/************************************Time complexity = O( N) *****************/
/************************************Space Complexity = O ( N )************************/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>answer(n);
        for(int i= 2*n-1 ; i>=0 ; i--) {
        while(!st.empty() && nums[st.top()] <= nums[i%n]) {
            st.pop();   
        }
            answer[i%n] = st.empty() ? -1 : nums[st.top()];
            st.push(i%n);
      }
        return answer;
    }
};

/************************************Optimal approach to find next greater element******/
/************************************Time complexity = O( N) *****************/
/************************************Space Complexity = O ( N )************************/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n , 0);
        stack<int>st;

        for(int i = n - 1 ; i >= 0 ; i--) {
            st.push(nums[i]);
        }
        for(int i = n - 1  ; i >= 0 ; i--) {
            while(st.size() > 0 && st.top() <= nums[i]) {
                st.pop();
            }

            ans[i] = st.size() == 0 ? -1 : st.top();

            st.push(nums[i]);
        }

        return ans;
    }
};