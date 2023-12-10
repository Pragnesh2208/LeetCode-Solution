/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(1)
 * Space Complexity = O(1)
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n == 0 || (n & (n - 1))) return -1;
        for(int i = 0 ; i< 32 ; i++) {
            if(n & (1 << i)) return i + 1;
        }
        return -1;
    }
};
