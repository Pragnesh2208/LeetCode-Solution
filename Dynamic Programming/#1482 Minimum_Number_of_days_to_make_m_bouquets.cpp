/*
Time Complexity = O(NLogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = INT_MAX ,  n = bloomDay.size() , right = INT_MIN;
        int ans = -1;

        for(int i = 0 ; i < n ; i++) {
            right  = max(right , bloomDay[i]);
            left = min(left , bloomDay[i]);
        }

        while(left <= right) {
            int mid = left + (right - left) / 2;
            int b = 0 ;
            int cnt = 0;

            for(int i = 0 ; i < n ; i++) {
                if(bloomDay[i] <= mid ) {
                    cnt++;
                } else {
                    cnt = 0;
                }

                if(cnt !=0 && cnt % k == 0 ) {
                    b++;
                    cnt = 0;
                }
            }

            if(b >= m ) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1; 
        }
        return ans;
    }
};