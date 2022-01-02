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