/************************************Optimal approach to Find Number with consecutive difference***********************************/ 
/**********************************************Time Complexity  = O (27 * 3 * N)***********************************************/
/***********************here we are using 3 nested loop so complexity of it is 3 * 3 * 3 and 3 for stoi function and N to concatination of string***************************************************/
/**********************************************Space Complexity  = O (N)**************************************************/
class Solution {
    private:
    bool isValid(string s) {
        if(s.length() > 3 )
            return false;
        if(s.front()=='0' && s.length() > 1)
            return false;
        int temp = stoi(s);
                    return temp >=0 && temp <= 255;
        
    }
    void getCombination (int len , string s , vector<string> &ans  ) {
       
        for(int i = 1 ; i <= 3 && i < len ; i++) {
            string first = s.substr(0 , i);
            if(isValid(first)) {
            for(int j = 1 ; j <=3 && i + j < len ; j++) {
                string second = s.substr(i , j);
                if(isValid(second)) {
                for(int k = 1 ; k <= 3 && k+i+j < len ; k++) {
                    string third = s.substr(i + j , k);
                    string four = s.substr(i + j + k );
                    if(isValid(third) && isValid(four)) {
                        ans.push_back(first + "." +second +"." + third + "." + four);
                    }
                  }
                }
              }
            }
        }
       
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> ans;
        string temp;
     getCombination(len , s , ans); 
        return ans;
    }
};

/************************************Optimal approach to Find Number with consecutive difference Using backtracking***********************************/ 
/**********************************************Time Complexity  = O ((3 ^ N) * N )***********************************************/
/**********************************************Space Complexity  = O (N)**************************************************/
class Solution {
    void backtrack(string address, int numberOfPartition, string& s,
                   vector<string>& result, int ind) {
        int n = s.length();
        if (numberOfPartition == 0) {
            int num = 0;
            if (ind == n)
                return;
            int i = ind;
            while (ind < n) {
                num = (num * 10) + (s[ind++] - '0');
                if (num > 255)
                    break;
            }

            if (num > 255 || n - i > 1 && s[i] == '0')
                return;
            result.push_back(address + s.substr(i));
        }

        int num = 0;
        for (int i = ind; i < n; i++) {
            num = (num * 10) + (s[i] - '0');
            if ((i != ind && s[ind] == '0') || num > 255) {
                break;
            }
            backtrack(address + s.substr(ind, i - ind + 1) + ".",
                      numberOfPartition - 1, s, result, i + 1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack("", 3, s, result, 0);
        return result;
    }
};