
/******************************Brute force approach To find first missing positive******************/
/******************************Time complexity = O(N)***********************************************/
/******************************Space complexity = O(N)**********************************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size(),ans;
        bool count[n+1];                                              //As missing postive can be from 1 to N+1
          for(int i=0;i<=n;i++)
              count[i]=false;
        for(int i=0;i<n;i++)
        {   if(nums[i]>0 && nums[i]<=n)
            count[nums[i]-1]=true;
        }
        for(int i=0;i<=n;i++)
            if(count[i]==false)
            {
                ans=i+1;
                break;
            }
        return ans;
    }
};
/*****************************=========Method-1=============****************************************/
/******************************optimal approach To find first missing positive**********************/
/******************************Time complexity = O(N)***********************************************/
/******************************Space complexity = O(1)**********************************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int  n=nums.size();
       bool one=false;
       for(int i=0;i<n;i++)  // checking if 1 is present in array or not if not we will return 1;
       {
           if(nums[i]==1)
           {
              one=true; 
           break;
           }    
       }
        if(one==false)
            return 1;
        for(int i=0;i<n;i++)     // elements below 0 and greater than size of array can never become first missing so we set them to 1
        {
            if(nums[i]<=0 || nums[i]>n)
                nums[i]=1;    
        }
        for(int i=0;i<n;i++)   // if any element is present in array we will go to that index and make them negative
        {
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
        }
        long ans=0;
        for( ans;ans<n;ans++)  // here now we know if any element is positive then its our first positive missing
        {
           if(nums[ans] > 0)
           {
               break;
           }
        }
        return ans+1;
    }
   };
/*****************************=========Method-2=============****************************************/
/******************************optimal approach To find first missing positive**********************/
/******************************Time complexity = O(N)***********************************************/
/******************************Space complexity = O(1)**********************************************/
   class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int  n=nums.size();
      int i=0;
        while(i<n)
      {
          if(nums[i]>0 && nums[i] <=n && nums[nums[i] - 1] != nums[i] )
          {
              swap(nums[i] ,nums[abs(nums[i])-1]);
          }
          else
              i++;
     }
        int ans=0;
        for(ans; ans<n;ans++)
        {
            if(nums[ans]!=ans+1)
                break;
        }
        return ans+1;
    }
   };