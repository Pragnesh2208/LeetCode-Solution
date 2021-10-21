/************************************Optimal approach to find Maximum Depth of Nesting Parentheses********/
/************************************Time complexity = O( N)**********************************************/
/************************************Space Complexity = O ( N )*******************************************/
class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char>st;
        int ans = 0;
        
        for(int  i = 0 ; i < n ; i++ ) {
            
            if(s[i]=='(') {
                st.push('('); 
                
            }
                else if(s[i] == ')') { 
                    st.pop();
                }
            
        int  l =st.size();
        ans = max(ans , l);
            
        }
        return ans;
    }
};