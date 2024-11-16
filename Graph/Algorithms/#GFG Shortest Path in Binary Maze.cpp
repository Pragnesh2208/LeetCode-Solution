/**
 * Time Complexity = O(M * N * LOG(M * N))
 * Space Complexity = O(M*N);
 */

class Solution {
    private:
    bool isCellValid(int row , int col , int totalRow , int totalCol) {
        if(row < 0 || col < 0 || row >= totalRow || col >= totalCol) return false;
        return true;
    }
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
    
        int totalRow = grid.size();
        int totalCol = grid.back().size();
        set<pair<int,pair<int,int>>>pq;
        vector<vector<int>>dist(totalRow , vector<int>(totalCol , INT_MAX));
        pq.insert({0 , source});
        dist[source.first][source.second] = 0;
        while(!pq.empty()) {
            int distance = pq.begin() -> first;
            pair<int,int> cell = pq.begin() -> second;
            pq.erase(pq.begin());
            vector<int>possibleRow = {0 , 0 , -1 , 1};
            vector<int>possibleCol = {-1 , 1 , 0 , 0};
            for(int i = 0 ; i < 4 ; i++) {
                int newRow = cell.first + possibleRow[i];
                int newCol = cell.second + possibleCol[i];
                if(isCellValid(newRow , newCol , totalRow , totalCol) && grid[newRow][newCol] && dist[newRow][newCol] > distance + 1 ) {
                    dist[newRow][newCol] = distance + 1;
                    pq.insert({distance + 1 , {newRow , newCol}});
                }
            }
        }
        
        return dist[destination.first][destination.second] == INT_MAX ? -1  : dist[destination.first][destination.second];
    }
};