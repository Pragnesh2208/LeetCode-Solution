/**********************************************Optimal approach to Construct The Lexicographical Largest Valid Sequence***********************************/ 
/**********************************************Time Complexity  = O (2 ^ N)*************************************************/
/**********************************************Space Complexity  = O ( 2 *  N - 1)**************************************************/
class Solution {
    private:
    bool getCombination(int pos , int n , vector<int> &ans , vector<bool> &visit) {
        if( pos == 2 * n - 1) {
            return true;
        }
        else if ( ans[pos] != 0)
            return getCombination(pos + 1 , n , ans , visit);
        else {
        for(int i = n ; i >=  1 ; i-- ) {
          
            if(i == 1) {
               if( visit[i] == false ) {
                   visit[i] = true;
                   ans[pos] = 1;
                   if(getCombination(pos + 1 , n , ans , visit)) {
                       return true;
                   }
                   else {
                       visit[i] = false;
                    ans[pos] = 0;
                   }
                   }
           }
           else {
               if( ( visit[i] == false && i  + pos < ans.size() && ans[ pos + i ] == 0) )  {
                   visit[i] = true;
                   ans[pos + i] = i;
                   ans[pos] = i;
                   if( getCombination( pos + 1 , n , ans , visit) ) 
                       return true;
                   else {
                       visit[i] = false;
                       ans[pos] = 0;
                       ans[pos + i] = 0;
                       }
                   }
               }
          }
        
        }  
        return false;
    } 

public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> ans( size , 0 );
        vector<bool> visit(  n + 1, false );
        
        getCombination(0 , n , ans , visit );
     
        return ans;
    }
};