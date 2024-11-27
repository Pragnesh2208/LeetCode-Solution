/**
 * Time Complexity = O(M * N * LOG(M * N))
 * Space Complexity = O(M*N);
 */

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        set<pair<int,pair<int,int>>>pq;
        int totalRow = heights.size();
        int totalCol = heights.back().size();
        vector<vector<int>>efforts(totalRow , vector<int>(totalCol , INT_MAX));
        
        pq.insert({0 , {0 , 0}});
               
        while(!pq.empty()) {
               int lastHeight = pq.begin() -> first;
               pair<int,int>cell = pq.begin() -> second;
               pq.erase(pq.begin());
               int currRow = cell.first;
               int currCol = cell.second;
                efforts[currRow][currCol] = min(efforts[currRow][currCol] , lastHeight);
               vector<int> possibleRow = {0 , 0 , -1 , 1};
               vector<int> possibleCol = {-1 , 1 , 0 , 0};
               
               for(int ind = 0 ; ind < 4 ; ind++) {
                   int newRow = currRow + possibleRow[ind];
                   int newCol = currCol + possibleCol[ind];
                   
                   if(newRow >= totalRow || newRow < 0 || newCol < 0 || newCol >= totalCol) continue;
                   
                   int heightDiff = abs(heights[currRow][currCol] - heights[newRow][newCol]);
                   if(max(heightDiff  , lastHeight) < efforts[newRow][newCol])
                   pq.insert({max(heightDiff , lastHeight) , {newRow , newCol}});
               }
        }
        
        return efforts[totalRow - 1][totalCol - 1];
        
    }
};