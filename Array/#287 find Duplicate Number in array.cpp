/******************** Brute force approach To find Duplicate number in array ****************/
/*******************Time complexity = O(n) **************************************************/
/*******************Space complexity = O(n)  ***********************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       vector<int>map(nums.size(),0);
        for(int x:nums)
            map[x]++;
        for(int y=0;y<map.size();y++)
            if(map[y]>=2)
                return y;
        return -1;
        
    }
};

/********************For mutable array**************************************************/
/******************** Optimal approach To find Duplicate number in array ****************/
/*******************Time complexity = O(n) **************************************************/
/*******************Space complexity = O(1)  ***********************************************/





class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size() , ans=0;
        for(long long i=0;i<n;i++)
        {
            if(nums[abs(nums[i])]>0)
                nums[abs(nums[i])]=-nums[abs(nums[i])];
            else
            {
                ans=abs(nums[i]);
            break;}
        }
        return ans;
    }
};
/********************For immutabble array**************************************************/
/******************** Optimal approach To find Duplicate number in array ****************/
/*******************Time complexity = O(n) **************************************************/
/*******************Space complexity = O(1)  ***********************************************/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
       int slow=nums[0];
    int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        
        }
        while(slow!=fast);
            
           slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};