/**********************************************Optimal approach to Find Ambigous Corrdinates***********************************/ 
/**********************************************Time Complexity  = O (N ^ 3)*************************************************/
/**********************************************Space Complexity  = O (N ^ 3)**************************************************/
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> res;
       for(int i = 1 ; i < n-2 ; i++) {
           
           vector<string> A = make(S.substr(1, i))  , B = make(S.substr(i + 1 , n - 2 - i)); 
           for(auto & a: A) 
               for(auto & b : B )
                   res.push_back("(" + a +", " + b + ")");
       }
        return res;
    }
    vector<string> make(string str) {
        int n = str.size();
        if( n == 0 ||( n > 1 && str[0]=='0' && str[n-1]=='0')) return {};
        if( n > 1 && str[0] == '0' ) return {"0."+ str.substr(1) };
        
        if(n == 1 || str[n-1] == '0')
            return {str};
        vector<string> res = {str};
        
        for(int i = 1 ; i < n ; i++) 
            res.push_back( str.substr(0 , i) + '.' + str.substr(i) );
        
        return res;
    }
   
};