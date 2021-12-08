/************************************Optimal solution to Generating Palindrome Partition********************************/
/************************************Time Complexity is O( N * 2^N) ****************************************************/
/************************************where N to store the path in ans  and 2^N for generating subsequence***************/
/************************************Space Complexity is O( N * N )*****************************************************/
/************************************where N to store subsequence in path vector and N for recurssion tree**************/
class Solution {
    private:
    void funcPartition(int ind , vector<string> &part , vector<vector<string>> &ans ,string &str) {
        int n = str.size();
        if(ind == n ) {
            ans.push_back(part);
        }
        for(int i = ind ; i < n ; i++) {
            if(isPalindrome(ind , i , str)) {
                part.push_back(str.substr(ind , i - ind + 1));
                funcPartition (i + 1 , part , ans , str);
                part.pop_back();
            }
        }
    }
    bool isPalindrome(int start , int end , string str) {
        bool ans = true;
        while(start <= end){
            if(str[start] != str[end]) { 
                ans = false;
                break;
            }
            start++;
            end--;
        }
        return ans;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>part;
        funcPartition(0 , part , ans ,s);
        return ans;
    }
};