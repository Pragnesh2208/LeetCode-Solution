/********************Optimal approach To find square of  sorted array*****************************/
/********************Time complexity = O(NLOGN) Big o of N LOG N**********************************/
/*******************Space complexity = O(1)*******************************************************/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n=nums.size(); 
        vector<int>ans;
      for(int i=0;i<n;i++)
      {
          if(nums[i] < 0)
       nums[i]=abs(nums[i]);
      }
        sort(nums.begin() , nums.end());
        for(int i=0;i<n;i++)
        {
            int res=0;
                res=pow(nums[i] , 2);
            ans.push_back(res);
        }
        return ans;
    }
};

/********************Optimal approach To find square of  sorted array*******************************/
/********************Time complexity = O(N)********************************************************/
/*******************Space complexity = O(1)*******************************************************/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n=nums.size(); 
        int ins_pos=nums.size()-1;
        vector<int>ans(n);
        int i=0, j=ins_pos;
      while(i<=j)
      {
          if(abs(nums[i]) > abs(nums[j]))
              ans[ins_pos--]=nums[i]*nums[i++];
          else
              ans[ins_pos--]=nums[j]*nums[j--];      
      }
        return ans;
    }
};