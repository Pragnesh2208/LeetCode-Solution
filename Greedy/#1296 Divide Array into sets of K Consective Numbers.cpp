/********************************Optimal approach to Using Greedy*****/
/********************************Time Complexity  = O (NLOGN)*************************************/
/********************************Space Complexity  = O (N)**************************************/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>freq;
        int maxFreq = 0;

        for(int i = 0 ; i < n ; i++) {
            freq[nums[i]]++;
        }

        for(auto it : freq) {
            if(freq[it.first] > 0 ) {
                for(int i = k  - 1; i >= 0 ;i--) {
                    if((freq[it.first + i] -= freq[it.first]) < 0) return false; 
                }
            }
        }

        return true;
    }
};