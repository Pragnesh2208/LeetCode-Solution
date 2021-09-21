/*********************Optimal approach To Find elements occur more than n/3 times************/
/*********************Time complexity = O(N)*************************************************/
/*********************Space complexity = O(1)  **********************************************/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int>ans;
        int ans1=-1,ans2=-1;
        int count1=0,count2=0;
        for(int i=0;i<nums.size() ;i++)
        {
            if(ans1==-1 ||nums[ans1]==nums[i])
            
            { 
                count1++;
                ans1=i;
            }
             else if(ans2==-1||nums[ans2]==nums[i])
            {
                count2++;
                ans2=i;
            }
            else if(count1==0)
            {
                count1++;
                ans1=i;
            }
            else if(count2==0)
            {
                count2++;
                ans2=i;
            }
            else{
                count1--;
                count2--;
            }
        }
        /* Check if the elements are actually occur more than n/3 times or not */
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[ans1])
                c1++;
             else if(nums[i]==nums[ans2])
                c2++;
        }   
        int n=nums.size();
        if(c1 > n/3)
            ans.push_back(nums[ans1]);
        if(c2 > n/3)
            ans.push_back(nums[ans2]);
        return  ans;
    }
};