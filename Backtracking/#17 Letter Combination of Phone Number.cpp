/********************************Optimal approach to Print Letter Combination of Phone Number*********/ 
/********************************Time Complexity  = O (  N ^ N)************************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
public:
    vector<string> combination(string &digits , vector<string> &str , int index) {
        if(index == digits.size()){
            return {""};
        }
        vector<string> temp = combination(digits , str , index+1);
        vector<string>ans;
        for(auto num :str[digits[index] - '0']) {
            for(auto cha : temp) {
                ans.push_back(num + cha);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>str = {"", "" , "abc","def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        if(!digits.size() < 1) {
            ans=combination(digits , str , 0);
        }
        return ans;}
};