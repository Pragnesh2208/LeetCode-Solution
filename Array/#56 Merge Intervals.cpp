/******************** Optimal approach To find Merge overlapping intervals of  array****************/
/*******************Time complexity = O(NlogN) *********************************************************/
/*******************Space complexity = O(1)*********************************************************/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin() ,intervals.end());
        vector<int>temp=intervals[0];
        for(auto i : intervals)
        {
            if(temp[1]>=i[0])
                temp[1]=max(i[1],temp[1]);
            else
            {
                ans.push_back(temp);
            temp=i;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};