/******************** Brute force approach To find Maximum sum of circular subarray ****************/
/*******************Time complexity = O(N^2) Big o of N square ************************************/
/*******************Space complexity = O(1)*******************************************************/

class Solution {
public:
   int kadane(vector<int>num)
    {
    }
    int maxSubarraySumCircular(vector<int>& nums) {
         int Max=nums[0];
       for(int  i=0;i<nums.size();i++) {
           int curr_max=nums[i];
           int curr_sum=nums[i];
          for(long j=1 ;j<n;j++)
           {
            int index=(i+j)% nums.size();
            curr_sum+=nums[index];
            curr_max+=max(curr_max,curr_sum);

           }
           Max=max(res,curr_max);

       }
       return Max;
    }
};


/******************** Optimal approach To find Maximum sum of circular subarray ****************/
/*******************Time complexity = O(N) **************************************************/
/*******************Space complexity = O(1)  ***********************************************/
class Solution {
public:
   int kadane(vector<int>num)
    {
        int Max=INT_MIN,sum=0;
        for(auto i:num)
        {
            sum+=i;
            if(sum>Max)
                Max=sum;
            if(sum<0)
                sum=0;
        }
        return Max;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int Maxsub=kadane(nums);
        if(Maxsub<0)
            return Maxsub;
        int Positive_sum=0;
        for(int  i=0;i<nums.size();i++)
        {
            Positive_sum+=nums[i];
            nums[i]=-nums[i];
            
        }
       
        int Negative_Sum=kadane(nums);
        return max(Maxsub , Positive_sum + Negative_Sum);
    }
};






