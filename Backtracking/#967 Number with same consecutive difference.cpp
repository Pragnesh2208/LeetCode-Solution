/************************************Optimal approach to Find Number with consecutive difference***********************************/ 
/**********************************************Time Complexity  = O (9 * 2^N)*************************************************/
/**********************************************Space Complexity  = O (2^N)**************************************************/
class Solution {
    private:
    void getCombination( int n , int k , vector<int> &ans , int temp ) {
        if( n == 0 ){
           ans.push_back(temp);
           return;
       }
        int last = temp % 10;
        
    if(last + k <= 9) 
        getCombination( n-1 , k , ans , temp * 10 + last + k  ); 
        
    if(last - k >=0 && last + k != last - k) 
        getCombination( n-1 , k , ans , temp * 10 + last - k );
        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(int i = 1 ; i <= 9  ;i++) 
        getCombination( n-1 , k , ans ,i);
        return ans;
    }
};