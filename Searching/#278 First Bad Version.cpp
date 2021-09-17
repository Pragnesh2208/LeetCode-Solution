 /******************************Optimal approach to find first bad Version***************/
/*******************************Time complexity = O(LOGN) Big o of log N***********************************/
/*******************************Space complexity = O(1)*******************************************************/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int low=0,high=n;
        while(low<=high)
        {
            int mid =low +(high -low)/2;
            if(isBadVersion(mid) && !isBadVersion(mid -1))
                return mid;
            else if(!isBadVersion(mid))
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return -1;
    }
};