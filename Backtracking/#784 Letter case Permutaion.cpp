/************************************Optimal solution to Generating Letter Case Permutation********************************/
/************************************Time Complexity is O(2^N) ****************************************************/
/************************************Space Complexity is O( N )*****************************************************/
class Solution {
    private:
    void getPermutation(vector<string> &str , string s, int ind) {
        int n = s.length();
        if(ind == n) {
            str.push_back(s);
            return;
        }
       if(isalpha(s[ind])) {
           s[ind] = char(toupper(s[ind]));
           getPermutation(str , s , ind +1);
           s[ind] = char(tolower(s[ind]));
       }
        getPermutation(str , s , ind +1);
    }
    
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>str;
        getPermutation(str,s,0);
        return str;
    }
};