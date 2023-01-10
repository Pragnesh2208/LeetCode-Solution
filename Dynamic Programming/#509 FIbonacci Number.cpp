/******************************Optimal Approach to Find Fibonacci Number*****************************/
/******************************Time Complexity is O(N)*********************************************/
/******************************Space Complexity is O(1)************************************************/
class Solution {
public:
    int fib(int n) {
       
        int prev1 = 1 , prev2 = 0;
        int curNum;

        if(n == 0 || n == 1)  curNum = n;

        for(int i = 2 ; i <= n ; i++ ){
            curNum = prev1 + prev2;
            prev2 = prev1;
            prev1 = curNum;
        }

        return curNum;
    }
};