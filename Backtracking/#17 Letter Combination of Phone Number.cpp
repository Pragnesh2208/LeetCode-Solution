/********************************Optimal approach to Print Letter Combination of Phone Number*********/ 
/********************************Time Complexity  = O (Number of Combination which are 4 * 4 * 3 * 3)************************/
/********************************Space Complexity  = O ( N )******************************/
class Solution {
private:
    vector<string> ans;
    vector<string> getDigitMap() {
        return {"",    "",    "abc",  "def", "ghi",
                "jkl", "mno", "pqrs", "tuv", "wxyz"};
    }

    void getCombinations(int index, string& currStr, string& digits,
                         vector<string>& digitMap) {
        if (currStr.length() == digits.length()) {
            ans.push_back(currStr);
            return;
        }
        char c = digits[index];

        for (int i = 0; i < digitMap[c - '0'].length(); i++) {
            currStr += digitMap[c - '0'][i];
            getCombinations(index + 1, currStr, digits, digitMap);
            currStr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        string str = "";
        vector<string> digitMap = this->getDigitMap();
        getCombinations(0, str, digits, digitMap);
        return this->ans;
    }
};