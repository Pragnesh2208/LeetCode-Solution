/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(k)
 * Space Complexity = O(1)
 * where k = number of 1 bit
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            n = n & (n-1);
            cout<<n<<endl;
            cnt++;
        }
        return cnt;
    }
};