/******************************optimal approach To Find 3Sum in array*******************************/
/******************************Time complexity = O(N^2) big oh of N square**************************/
/******************************Space complexity = O(N)**********************************************/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int x=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i==0||nums[i]!=nums[i-1])
            {
                int left=i+1;
                int right=n-1;
                while(left < right)
                {
                    if(nums[left]+nums[right]+nums[i]==0)
                    { ans.push_back({nums[left] , nums[right], nums[i]});
                     while(nums[left]==nums[left+1] && left < right-1)
                        left++;
                    left++;
                      while(nums[right]==nums[right-1] && right-1 > left)
                        right--;
                    right--;
                    }
                    else if(nums[left]+nums[right]+nums[i] < 0)
                    {  while(nums[left]==nums[left+1] && left < right-1)
                        left++;
                    left++;
                    }
                    else{
                    while(nums[right]==nums[right-1] && right-1 > left)
                        right--;
                    right--;
                    }
                }
            }
        }
        return ans;
    }
};