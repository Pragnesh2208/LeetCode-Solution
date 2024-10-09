/*****************************Optimal solution of 01 Matrix******************************/
/****************************Time Complexity = O( V * E) As we are using adjacent matrix***********/
/***************************Space Complexity = O(N) ******************/
class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int totalRow = mat.size();
        int totalCol = mat.back().size();
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(totalRow, vector<bool>(totalCol, false));
        vector<vector<int>> memo(totalRow, vector<int>(totalCol, 1e8));
        vector<int> possibleRow = {0, 0, 1, -1};
        vector<int> possibleCol = {-1, 1, 0, 0};
        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (mat[row][col] == 0) {
                    que.push({row, col});
                    visited[row][col] = true;
                    memo[row][col] = 0;
                }
            }
        }

        while (!que.empty()) {
            int sz = que.size();

            while (sz--) {
                pair<int, int> front = que.front();
                que.pop();

                int row = front.first;
                int col = front.second;
                for (int i = 0; i < 4; i++) {
                    int newRow = row + possibleRow[i];
                    int newCol = col + possibleCol[i];
                    if (newRow < 0 || newRow >= totalRow || newCol < 0 ||
                        newCol >= totalCol || visited[newRow][newCol])
                        continue;
                    memo[newRow][newCol] = memo[row][col] + 1;
                    visited[newRow][newCol] = true;
                    que.push({newRow, newCol});
                }
            }
        }
        return memo;
    }
};