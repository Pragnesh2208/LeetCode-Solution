/**
 * Optimal Approach to find the Solution
 * Time Complexity = O(N)
 * Space Complexity = O(1)
*/
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int xorOfAll = 0;
        for(int i = 0 ; i < n ; i++) {
            xorOfAll ^= arr[i];
            xorOfAll ^= (i + 1);
        }
        
        int setBit = xorOfAll & ~(xorOfAll - 1);
        vector<int>ans{0,0};
        
        for(int i = 0 ; i < n ;i++) {
            if(arr[i] & setBit) {
                ans[0] ^= arr[i];
            } else {
                ans[1] ^= arr[i]; 
            } 
            
            if( (i + 1) & setBit) {
                ans[0] ^= ( i + 1);
            } else {
                ans[1] ^= (i + 1);
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(ans[0] == arr[i])  break;
            else if(ans[1] == arr[i]) {
                swap(ans[0] , ans[1]);
                break;
            }
        }
        
        return ans;
    }
};