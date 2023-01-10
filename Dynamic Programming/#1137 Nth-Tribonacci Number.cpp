/******************************Optimal Approach to Find Nth-Tribonacci Number*****************************/
/******************************Time Complexity is O(N)*********************************************/
/******************************Space Complexity is O(1)************************************************/
class Solution {
public:
    int tribonacci(int n) {
        int prev1 = 0  , prev2 = 1 , prev3 = 1;
        int curNum;

        if(n == 0 || n == 1 || n == 2) 
            if(n == 2) curNum = 1;
            else curNum = n;
        
        for(int i = 3 ; i <=n ; i++ ) {
            curNum = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = curNum;
        }
        return curNum;
    }
};