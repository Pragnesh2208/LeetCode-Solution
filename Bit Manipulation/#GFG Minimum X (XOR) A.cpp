/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N)
 * Space Complexity = O(1)
 * 
*/
class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int setBitOfB = 0;
        for(int i = 31 ; i >= 0 ; i--) {
            if((1 <<i)  & b) setBitOfB++;
        }
        
        int x = 0;
        
        for(int i = 31 ; i >= 0 && setBitOfB > 0 ; i--) {
            if((1 << i ) & a) {
                x |= (1 << i);
                setBitOfB--;
            }
        }
        
        for(int i = 0 ; i <= 31 && setBitOfB > 0 ; i++ ) {
            if(!((1 << i ) & a )) {
                x |= (1 << i);
                setBitOfB--;
            }
        }
        
        return x;
    }
};
