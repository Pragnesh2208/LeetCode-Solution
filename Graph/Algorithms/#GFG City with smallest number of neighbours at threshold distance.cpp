/**
 * Optimal Solutions
 * Time Complexity = O(N^3)
 * Space Complexity = O(N^2)
 */
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int dt) {
        // Your code here
        vector<vector<int>>graph(n , vector<int>(n , 1e9));
        
        for(vector<int>edge : edges) {
            int src = edge[0];
            int dist = edge[1];
            int weight = edge[2];
            graph[src][dist] = weight;
            graph[dist][src] = weight;
        }
        
        int totalVert = n;
        for(int via = 0 ; via < totalVert ; via++) {
            for(int src = 0 ; src < totalVert ; src++) {
                for(int dist = 0 ; dist < totalVert ; dist++) {
                    if(src == dist) graph[src][dist] = 0;
                    graph[src][dist] = min(graph[src][dist] , graph[src][via] + graph[via][dist]);
                    if(graph[src][dist] > dt) {
                        graph[src][dist] = 1e9;

                    }
                  
                }
            }
        }
        int minVisit = totalVert;
        int ans = 0;
        for(int src = 0 ; src < totalVert ; src++) {
            int visit = 0;
            for(int dist = 0 ; dist < totalVert; dist++) {
                if(graph[src][dist] != 1e9) {
                    visit++;
                }
            }
            if(visit <= minVisit) {
                minVisit = visit;
                ans = src;
            }
        }
        return ans;
    }
};