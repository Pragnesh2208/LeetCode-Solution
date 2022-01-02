/************************************Optimal approach to Split Array into Fibonacci Sequence***********************************/ 
/**********************************************Time Complexity  = O (10 ^ N)*************************************************/
/*********************************************At each level, we branch at most 10 times, as the for-loop will run until Integer.MAX_VALUE is reached (which is maximum 10 digits in length).Our recursive calls go to a maximum depth of       N********************************************************************/
/**********************************************Space Complexity  = O (N) which is the Depth of Recursion Tree**************************************************/
class Solution {
    private:
    bool getCombination(int ind , string st , vector<int> &ans) {
        if(ind == st.size() ) {
             if(ans.size()>=3)
                 return true;
            else
                return false;
        }
        
        int n = st.size();
        long num = 0;
        for(int i = ind ; i < n ; i++ ) {
            if(i > ind && st[ind] == '0')
                return false;
            
             num = num*10 + (st[i] - '0');
            
            if (num > INT_MAX) 
              break;
        
            int size = ans.size();
            
            if(size >= 2 && num - ans[size - 1] - ans[size - 2]  > 0) 
                break;
            
         if( size <= 1 || num - ans[size - 1] - ans[size - 2] == 0 ) {
             
                ans.push_back((int)num);
                if(getCombination(i + 1 , st , ans) == true) { 
                    return true;
                }
                    ans.pop_back();
            }
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        getCombination( 0 , num , ans );
        return ans;
    }
};