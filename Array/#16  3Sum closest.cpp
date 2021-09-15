/******************** Brute Force approach To find 3Sum closest in  array***********************/
/*******************Time complexity = O(N^3) Big o of N cube ********************************************************/
/*******************Space complexity = O(1)*********************************************************/
class Solution {
public:
    
     
    int threeSumClosest(vector<int>& nums, int target) {
        int parity=1;
        int diff = INT_MAX;
        for(int i=0; i<=nums.size()-3; i++){
            for(int j=i+1; j<=nums.size()-2; j++){
                for(int k=j+1; k<=nums.size()-1; k++){
                    int temp = nums[i]+nums[j]+nums[k]-target;
                    if(diff >= abs(temp)){
                        diff = abs(temp);
                        if(temp < 0) parity=-1;
                        else parity=1;
                    }
                }
            }
        }
        return diff*parity+target;
    }
};
/******************** Brute Force approach To find 3Sum closest in  array***************************/
/*******************Time complexity = O(N^2) Big o of N square**************************************/
/*******************Space complexity = O(1)*********************************************************/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     sort(nums.begin() ,nums.end());
        int ans=0;
        int n=nums.size();
        int mindiff=INT_MAX;
        for (int i=0;i<n;i++)
        {
            int start = i+1;
            int end = n-1;
            int diff=0;
            int sum=0;
            while(start<end)
            {
                sum= nums[start]+nums[end]+nums[i];
                diff =abs(target - sum);
                if(mindiff > diff )
                {
                    ans=sum;
                    mindiff=diff;
                }
                if(sum==target){
                    return sum;}
                else if (sum > target)
                        end--;
                    else 
                        start++;
                    
                }
            }
      return ans;
    }  
};