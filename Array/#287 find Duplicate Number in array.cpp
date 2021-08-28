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