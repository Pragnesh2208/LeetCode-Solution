/**
 * Optimal Approach to solve find ways to arrive at destination
 * Time Complexity = O(E log V)
 * Space Complexity = O(E+V)
 */

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int,int>>>graph(n);
        vector<pair<int,int>>dist(n , pair<int,int>({INT_MAX , 0}));
        
        set<pair<int,pair<int,int>>>pq;
        pq.insert({0 , {0 , -1}});
        dist[0]={0 , 1};
        
        int totalRoads = roads.size();
        for(vector<int>road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            graph[u].push_back({v , time});
            graph[v].push_back({u , time});
        }
        
        while(!pq.empty()) {
            int cost = pq.begin()->first;
            int src = pq.begin()->second.first;
            int parent = pq.begin()->second.second;
            pq.erase(pq.begin());
            if(cost > dist[src].first) { 
                continue;
            }

            for(pair<int,int>road : graph[src]) {
                int newSrc = road.first;
                int newCost = road.second + cost;
                if(dist[newSrc].first == newCost) dist[newSrc].second = ((dist[newSrc].second % int(1e9 + 7) + dist[src].second % int(1e9 + 7)) % int(1e9 + 7));
                
                if(dist[newSrc].first > newCost ) {
                    dist[newSrc].first = newCost;
                    dist[newSrc].second =  dist[src].second;
                    pq.insert({newCost , {newSrc , src}});
                }
            }
        }
        
        return dist[n-1].second;
    }
};