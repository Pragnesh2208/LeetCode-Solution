/********************************Optimal approach to using Greedy by Relative cost********/ 
/********************************Time Complexity  = O (NLogN)*****************************/
/********************************Space Complexity  = O (1)******************************/

class Solution {
public:
    static bool relativeCost(vector<int> & first , vector<int> &second) {
        return (first[1] - first[0]) > (second[1] - second[0]);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalCost = 0 , n = costs.size();
        sort(costs.begin() , costs.end() , relativeCost);
        for(int i = 0 ; i < n ; i++) {
            int j = (i < (n / 2)) ? 0 : 1;
            totalCost += costs[i][j];
        }

        return totalCost;
    }
};