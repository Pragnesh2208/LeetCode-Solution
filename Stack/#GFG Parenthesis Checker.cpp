/************************************Optimal Approach to Solve Parenthesis Checker*****/
/************************************Time complexity = O( N ) ************************************/
/************************************Space Complexity = O ( N )**********************************/
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        int n = s.size();
        stack<char>st;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                
                if(s[i] == '}' && st.top() != '{') return false;
                if(s[i] == ')' && st.top() != '(') return false;
                if(s[i] == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        
        return st.empty();
    }

};