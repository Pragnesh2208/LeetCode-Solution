/********************************Optimal approach to Generate Parentheses****************************************/ 
/********************************Time Complexity  = O ( 2 ^ N ) where N = Length of Parentheses*********/
/********************************Space Complexity  = O ( N ) where N = Length of Parentheses******************/
class Solution {
public:
    void generate(vector<string>&ans , string str , int &n , int open , int close) {
        if(close == n){
            ans.push_back(str);
            return;
        }
        if(open < n)
            generate(ans , str+'(' , n , open+1 , close);
        if(close < open) 
             generate(ans , str+')' , n , open , close +1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(ans , "" , n , 0 , 0);
        return ans;
    }
};