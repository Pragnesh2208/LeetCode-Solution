/************************************Optimal approach to Remove outmost Parentheses********/
/************************************Time complexity = O( N)*******************************/
/************************************Space Complexity = O ( 1 )****************************/
class Solution {
public:
   string removeOuterParentheses(string S) {
        string res;
       int open = -1;
       for(char c : S) {
           if(c == '(' && open++ >=0) {
              res+=c;
           }
           else if(c == ')' && open-- >0 ) {
               res +=c;
           }
       
     
       }
       return res;
   }
};