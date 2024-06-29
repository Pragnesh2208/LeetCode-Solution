/************************************Optimal approach to Split Array into Fibonacci Sequence***********************************/ 
/**********************************************Time Complexity  = O (2 ^ N)*************************************************/
/**********************************************Space Complexity  = O (N) which is the Depth of Recursion Tree**************************************************/
class Solution {
    bool backtracking(int ind, string& s, vector<int>& result) {
        int n = s.length();
        if (ind == n) {
            return result.size() > 2;
        }

        int num = 0;
        for (int i = ind; i < n; i++) {
            int tempNum = s[i] - '0';
            if (num > (INT_MAX - tempNum) / 10)
                return false;
            num = (num * 10) + tempNum;
            if (i != ind && s[ind] == '0')
                return false;

            long long temp1 = 0;
            long long temp2 = 0;
            if (result.size() >= 2) {
                temp1 = result.back();
                temp2 = result[result.size() - 2];
            }

            if (result.size() < 2 || temp1 + temp2 == num) {
                result.push_back(num);
                if (backtracking(i + 1, s, result)) {
                    return true;
                }
                result.pop_back();
            }
        }
        return false;
    }

public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        backtracking(0, S, result);
        return result;
    }
};