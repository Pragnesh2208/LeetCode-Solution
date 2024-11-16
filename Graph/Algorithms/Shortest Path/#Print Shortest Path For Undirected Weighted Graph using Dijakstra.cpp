/*****************************Sortest Path Of Undirected/Directed weighted graph using Dijakstra Algorithm*******/
/****here we are visiting every vertices so for wrost case our time complexity for visiting every vertices is O(E)
 And we also use Priority queue and at Max we can add N vertices so for that our time complexity will be O(E) * Log(N)***********/
/***************************Space Complexity = O(N) as we are using Priority queue and at Max we will store N vertices********/
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adjList(n + 1);
        vector<int>parent(n + 1, -1);
        vector<int>dist(n + 1 , 1e9);
        for(vector<int>edge : edges) {
            int source = edge[0];
            int di = edge[1];
            int wt = edge[2];
            adjList[source].push_back({di , wt});
            adjList[di].push_back({source , wt});
        }
        
        set<pair<int,int>>pq;
        pq.insert({0 , 1});
        parent[1] = -1;
        dist[1] = 0;
        while(!pq.empty()) {
            int node =  pq.begin() -> second , wt =  pq.begin() -> first;
            pq.erase(pq.begin());
            for(const pair<int,int>adj : adjList[node]) {
                int childNode = adj.first ,  childWt = adj.second;
                if( dist[childNode] > childWt + wt) {
                    dist[childNode] = childWt + wt;
                    parent[childNode] = node;
                    pq.insert({dist[childNode] , childNode});
                }
            }
        }
        if(parent[n] == -1) return {-1};
        int node = n;
        vector<int>path;
        path.push_back(dist[n]);
        while(node != -1) {
               path.push_back(node);
               node = parent[node];
        }
        
     
        reverse(path.end() , path.begin());
        return path; 
    }
};
