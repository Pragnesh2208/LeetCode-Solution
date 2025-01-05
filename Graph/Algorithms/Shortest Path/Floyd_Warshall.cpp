/**
 * Floyd Warshall Algorithm to Find Shortest path between many sources to many destination
 * Time Complexity = O(N^3)
 * Space Complexity = O(1)
 */
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int totalVert = mat.size();
        for(int source = 0 ; source < totalVert ; source++) {
            for(int dist = 0 ; dist < totalVert ; dist++){
            if(mat[source][dist] == -1) mat[source][dist] = 1e9;
            if(source == dist) mat[source][dist] = 0;
            }
        }
        for(int via = 0 ; via < totalVert ; via++) {
            for(int source = 0 ; source < totalVert ; source++){
                for(int dist = 0 ; dist < totalVert ; dist++) {
                    mat[source][dist] = min(mat[source][dist] , mat[source][via] + mat[via][dist]);

                }
            }
        }
        
          for(int source = 0 ; source < totalVert ; source++) {
            for(int dist = 0 ; dist < totalVert ; dist++){
            if(mat[source][dist] == 1e9) mat[source][dist] = -1;
          
            }
        }
    }
};