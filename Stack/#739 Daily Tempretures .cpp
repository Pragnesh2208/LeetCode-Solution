/************************************Brute Force approach to find Daily temperatures******/
/************************************Time complexity = O (N)******************************/
/************************************Space Complexity = O (N)*****************************/
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
/************************************Optimal approach to find Daily temperatures******/
/************************************Time complexity = O (N)******************************/
/************************************Space Complexity = O (1)*****************************/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        int hottest = 0;

        for(int i = n-1 ; i >= 0 ; i-- ){

            if(temperatures[i] >= hottest) {
                hottest = temperatures[i];
                continue;
            }

            int day = 1;

            while( day < n &&  temperatures[i] >= temperatures[i+day]) {
                day += answer[i+day];
            }

            answer[i] = day;
        }

        return answer;
    }
};