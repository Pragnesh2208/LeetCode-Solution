/******************** Optimal approach To find Two sum equal to target************************/
/*******************Time complexity = O(N)**************************************************/
/*******************Space complexity = O(1)  ***********************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        vector<int>ans;
        while(start < end)
        {
            if(nums[start]+nums[end] == target)
            {
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
            else if(  nums[start]+nums[end] > target)
                end--;
            else
                start++;
        }
        return ans;
    }
};