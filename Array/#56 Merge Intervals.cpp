/******************** Optimal approach To find Merge overlapping intervals of  array****************/
/*******************Time complexity = O(NlogN) *********************************************************/
/*******************Space complexity = O(1)*********************************************************/


class Solution { 
   
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        sort(intervals.begin() , intervals.end() );
        int n = intervals.size();
        
        for(int i = 0 ; i < n; i++){
            
            if(ans.size() != 0 && ans[ans.size() - 1][1] >= intervals[i][0] ) {
                if(intervals[i][1] > ans[ans.size() - 1][1])
                ans[ans.size() - 1][1] = intervals[i][1];
            }
            else
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};