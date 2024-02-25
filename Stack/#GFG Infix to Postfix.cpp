/************************************Optimal Approach to Convert Infix to Postfix*****/
/************************************Time complexity = O( N ) ************************************/
/************************************Space Complexity = O ( N )**********************************/
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string ans = "";
        int len = s.size();
        stack<pair<char , int>>st;
        for(int i = 0 ; i < len ; i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '(' || s[i] == ')') {
                if(st.empty() || s[i] == '(') {
                    if(s[i] == '+' || s[i] == '-')
                        st.push({s[i] , 1});
                    else if(s[i] == '*' || s[i] == '/') {
                        st.push({s[i] , 2});
                    } else {
                        st.push({s[i] , 3});
                    }
                } else if(s[i] == ')') {
                    while(st.top().first != '(') {
                        char c = st.top().first;
                        ans += c;
                        st.pop();
                    }
                    st.pop();
                } else  {
                    int operatorVal = 0;
                    if(s[i] == '+' || s[i] == '-') {
                        operatorVal = 1;
                    } else if(s[i] == '*' || s[i] == '/') {
                        operatorVal = 2;
                    } else {
                        operatorVal = 3;
                    }
                    while(!st.empty() && st.top().first != '(' && st.top().second >= operatorVal) {
                            char c = st.top().first;
                            ans += c;
                            st.pop();
                    }
                        
                    st.push({s[i] , operatorVal});
                }
            } else {
                ans += s[i];
            }
        }
        
        while(!st.empty()) {
               char c = st.top().first;
                            ans += c;
                            st.pop();
        }
        return ans;
    }
};