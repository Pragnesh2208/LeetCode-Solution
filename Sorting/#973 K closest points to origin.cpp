/******************************Brute FOrce approach to find K closest points to origin******************/
/******************************Time complexity = O(NLogN +N)***********************************************/
/******************************Space complexity = O(N)**********************************************/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int , pair<int,int>>> ans;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            ans.push_back({dist,{points[i][0],points[i][1]}});
        }
        sort(ans.begin(),ans.end());
        vector<vector<int>>a;
        for(int i=0;i<k;i++)
        {
            a.push_back({ans[i].second.first , ans[i].second.second});
        }
        return a;
    }
};