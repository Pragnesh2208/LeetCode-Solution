/******************** Only approach To find Maximum sum of subarray****************/
/*******************Time complexity = O(N) **************************************************/
/*******************Space complexity = O(1)  ***********************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=INT_MIN,sum=0;
        for(auto i:nums)
        {
            sum+=i;
            if(sum>max)
                max=sum;
            if(sum<0)
                sum=0;
        }
        return max;
        
    }
};