 /******************************Optimal approach to find first bad Version***************/
/*******************************Time complexity = O(LOGN) Big o of log N***********************************/
/*******************************Space complexity = O(1)*******************************************************/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long long left = 0 , right = n;
        
        while( left < right ){
            int mid =  (left + right)/2;
                
            if(isBadVersion(mid) == false)
                left= mid + 1;
            else
                right = mid;
        }
        return right;
    }
};