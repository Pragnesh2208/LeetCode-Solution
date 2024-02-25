/************************************Optimal Approach to Evaluate Postfix Expression*****/
/************************************Time complexity = O( N ) ************************************/
/************************************Space Complexity = O ( N )**********************************/
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        int n = s.size();
        
        stack<int>st;
        
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                
                int calc = 0 ;
                switch (s[i]) {
                    case '+' : {
                        calc = second + first;
                        break;
                    }
                    case '-' : {
                        calc = second - first;
                        break;
                    }
                    case '*' : {
                        calc = second * first;
                        break;
                    }
                    case '/' : {
                        calc = second / first;
                        break;
                    }
                }
                
                st.push(calc);
            }
            else {
                st.push((s[i] - '0'));
            }
        }
        
        return st.top();
    }
};
