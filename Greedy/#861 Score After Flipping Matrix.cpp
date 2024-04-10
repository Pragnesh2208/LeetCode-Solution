/********************************Optimal approach to Solve Using Greedy********/ 
/********************************Time Complexity  = O ( N*M )******************/
/********************************Space Complexity  = O (1)*********************/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid.back().size();
        int res = (1 << (m - 1)) * n;

        for(int j = 1 ; j < m ; j++) {
            int cur = 0;
            for(int i = 0 ; i < n ; i++) {
                if(grid[i][j] == grid[i][0]) cur++;
            }
            res += max(cur , n -  cur) * (1 << m - j - 1);
        }
        return res;
    }
};