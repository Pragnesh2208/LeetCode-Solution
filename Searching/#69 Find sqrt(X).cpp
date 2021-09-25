/******************************Optimal approach To Find sqrt(x)***************************************/
/*****************************Time complexity = O(LOGN)***********************************************/
/*****************************Space complexity = O(1)*************************************************/
class Solution {
public:
    int mySqrt(long long x) {
        long long low = 0,high = x+1; 
        while(low<high) {
            long long mid = low+(high -low)/2;
            if(mid*mid>x) 
                high = mid ;
            else low = mid+1;
        }
        return low-1;
    }
};