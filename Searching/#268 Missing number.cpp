/********************Optimal approach To Find missing number in array***************/
/*******************Time complexity = O(N)******************************/
/*******************Space complexity = O(1)********************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum1=(n*(n+1)/2);
        for(auto i:nums)
            sum1-=i;
        return sum1;
    }
};