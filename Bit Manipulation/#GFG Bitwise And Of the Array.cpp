/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N)
 * Space Complexity = O(1)
 * 
*/
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
        int ans = N;
        int setBitX = 0;
        for(int i = 31 ; i >= 0 ; i-- ) {
            if( (1 << i) & X ){
                setBitX |= (1 << i);
            } else {
                int temp = setBitX | (1 << i);
                int dontModify = 0;
                for(int j = 0 ; j < N ; j++) {
                    
                    if( (temp & A[j]) == temp ) dontModify++;
                }

                ans = min(ans , N - dontModify);
            }
        }
        return ans;
    }
};