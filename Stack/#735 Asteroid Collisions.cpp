/************************************Optimal approach to Asteroid Collisions******************************/
/************************************Time complexity = O( N)**********************************************/
/************************************Space Complexity = O ( N )*******************************************/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int ast : asteroids) {
            bool flag = true;
            while(!st.empty() && ast < 0 && st.top() > 0) {
                
                if(-ast > st.top()) {
                    st.pop();
                   
                }
                else if(-ast == st.top()) {
                    st.pop();
                    flag = false;
                    break;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                st.push(ast);
            }
        }
        vector<int>ans(st.size());
        for(int  i = st.size()- 1 ; i >= 0 ; i-- ){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};

// Clean Code & Short Code

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        for(int i = 0 ; i < n ; i++) {
            while(nums[i] < 0 && !st.empty() && st.top() > 0 && abs(nums[i]) > st.top()) {
                st.pop();
            }
            if( !st.empty() && nums[i] < 0 &&  abs(nums[i]) == st.top()) st.pop();
            else if(nums[i] > 0 || st.empty() || abs(nums[i]) > st.top() )
            st.push(nums[i]);
        }

        vector<int>ans(st.size());
        while(!st.empty()) {
            ans[st.size() - 1] = st.top();
            st.pop();
        }
        return ans;
    }
};