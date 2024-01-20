/*Solution Using Better Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(N)*/
class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int ans = 0 , n = nums.size();
        unordered_map<long long int , long long int>mp;
        mp[0] = 1;
        long long int sum = 0;

        for(int i = 0 ; i < n ; i++) {

            sum += nums[i];
            ans += mp[sum - goal];
            mp[sum]++;
        }
        return ans;
    }
};


/*Solution Using Optimal Appraoch*/
/*Time Complexity = O(N)*/
/*Space Complexity = O(1)*/
class Solution {
    int numberOfSubarrayWithTargetSum( vector<int> &nums , int goal) {
        int n = nums.size() , ans = 0;
        long long int count = 0;

        for(int i = 0 , j = 0 ; i < n ; i++) {
            count += nums[i];

            while(count > goal && j <= i) {
                count -= nums[j++];
            }
            ans += (i - j + 1);
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numberOfSubarrayWithTargetSum(nums , goal) - numberOfSubarrayWithTargetSum(nums , goal - 1);
    }
};