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
