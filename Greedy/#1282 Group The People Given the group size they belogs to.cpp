/********************************Optimal approach using greedy*********************************/ 
/********************************Time Complexity  = O (N) ***********************************/
/********************************Space Complexity  = O (N) **********************************/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>ans , bucket(n + 1);

        for(int i = 0 ; i < n ; i++) {
            bucket[groupSizes[i]].push_back(i);
        }

        for(int i = 0 ; i <= n ; i++) {

            if(bucket[i].size() >= 1) {
                int k = ans.size();
                ans.push_back({});
                for(int j = 0 ; j < bucket[i].size() ; j++) {
                    ans[k].push_back(bucket[i][j]);
                    if(ans[k].size() == i && j + 1 < bucket[i].size()) {
                        ans.push_back({});
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};