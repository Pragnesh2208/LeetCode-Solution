/****************Sub-Optimal approach to solve problem using memoization*************/
/****************Time Complexity = O(N)******************************************/
/****************Space Complexity = O(N)*****************************************/

class Solution {
    int maxAmount(int house , vector<int>&nums  , vector<int>&dp) {
        int n = nums.size();
        if(dp[house] != -1) return dp[house];

        int nextHouse = house + 1;
        int nextOneHouse =  nextHouse + 1 < n ? maxAmount(nextHouse + 1, nums , dp) : 0;
        int nextTwoHouse = nextHouse + 2 < n ? maxAmount(nextHouse + 2 , nums , dp) : 0;

        return dp[house] =  max(nextOneHouse , nextTwoHouse) + nums[house];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>cache(n + 1  , -1);
        cache[n] = 0;
        int withLast = max( maxAmount(1 , nums , cache) ,  maxAmount(2 , nums , cache));
        vector<int>cache1(n + 1 , -1);
        cache1[n - 1] = 0;
        nums.pop_back();
        int withOne = max(maxAmount(0 , nums , cache1) , maxAmount(1 , nums , cache1));
        return max(withLast , withOne);
    }
};

/****************Sub-Optimal approach to solve problem using iteration*************/
/****************Time Complexity = O(N)****************************************/
/****************Space Complexity = O(N)***************************************/
class Solution {    
    int maxAmountItr(int startHouse , vector<int>&nums) {
        int n = nums.size();
        vector<int> dp(n + 1 , 0);
        for(int currHouse = n-1 ; currHouse >= startHouse ; currHouse--) {
            int nextHouse = currHouse + 1;
            int nextOneHouse =  nextHouse + 1 < n ? dp[nextHouse + 1] : 0;
            int nextTwoHouse = nextHouse + 2 < n ? dp[nextHouse + 2] : 0;
            dp[currHouse] = max(nextOneHouse , nextTwoHouse) + nums[currHouse];
        }
        return max(dp[startHouse] , dp[startHouse + 1]);
    }
    int tabulation( vector<int>&nums) {
        int withoutFirst = maxAmountItr(1 , nums);
        nums.pop_back();
        int withFirst = maxAmountItr(0 , nums);
        return max(withFirst , withoutFirst);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return tabulation(nums);


    }
};


/****************Optimal approach to solve problem*************/
/****************Time Complexity = O(N)************************/
/****************Space Complexity = O(1)***********************/
class Solution {
    int maxAmountSpaceOptimized(int startHouse , vector<int>&nums) {
        int n = nums.size();
        int prev1 = 0, prev2  = 0 , prev3 = 0;
        for (int currHouse = n - 1; currHouse >= startHouse; currHouse--) {
            int nextHouse = currHouse + 1;
            int nextOneHouse = nextHouse + 1 < n ? prev1 : 0;
            int nextTwoHouse = nextHouse + 2 < n ? prev2 : 0;
            prev2 = prev1;
            prev1 = prev3;
            prev3 = max(nextOneHouse, nextTwoHouse) + nums[currHouse];
        }
        return max(prev3, prev1);
    }

    int tabulation(vector<int>& nums) {
        int withoutFirst = maxAmountSpaceOptimized(1, nums);
        nums.pop_back();
        int withFirst = maxAmountSpaceOptimized(0, nums);
        return max(withFirst, withoutFirst);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return tabulation(nums);
    }
};