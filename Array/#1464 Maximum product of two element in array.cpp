/******************** Brute force  approach To find Maximum product of two elements in  array****************/
/*******************Time complexity = O(N logN)*************************************************************/
/*******************Space complexity = O(1)****************************************************************/
class Solution {
    public:
    int maxProduct(vector<int>& nums){
        sort(nums.begin(), nums.end(),greater<int>());
        return (nums[0]-1) * (nums[1]-1);
    }
    
}

/******************** Optimal approach To find Maximum product of two elements in  array****************/
/*******************Time complexity = O(N)*************************************************************/
/*******************Space complexity = O(1)***********************************************************/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int max1=INT_MIN ,max2=INT_MIN;
        for(int i:nums)
        {
            if(i>=max1)
            {
                max2=max1;
             max1=i;
            }
            else if(i>max2)
            {
                max2=i;
            }
        }
        return (max1-1)*(max2-1);
    }
};