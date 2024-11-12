/*****************************Find Sortest Path for DAG (Directed Acyclic weighted graph)*******/
/*****************************Topological sort usign dfs*******************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/

class Solution {
    private:
    void topoSort(vector<vector<pair<int , int>>>&graph, int vertex , vector<bool>&visit , stack<int>&st) {
        if(visit[vertex]) return;
        visit[vertex] = true;
        for(pair<int,int> adj : graph[vertex]) {
            int v = adj.first;
            topoSort(graph , v , visit , st);
        }
        st.push(vertex);
    }
    
  public:
    vector<int> shortestPath(int V, int totalEdge, vector<vector<int>>& edges) {
        // code here
        vector<int>dist(V , 1e9);
        vector<vector<pair<int , int>>>graph(V);
        vector<bool>visit(V , false);
        stack<int>st;
        
        for(int edge = 0 ; edge < totalEdge ; edge++ ) {
            int source = edges[edge][0];
            int dist = edges[edge][1];
            int wt = edges[edge][2];
            graph[source].push_back({dist , wt});
        }
        
        for(int vertex = 0 ; vertex < V ; vertex++) {
            if(!visit[vertex]) topoSort(graph , vertex , visit , st);
        }
        
        while(!st.empty()) {
            int node = st.top();
            dist[node] = -1;
            if(node == 0) break;
            st.pop();
        }
        
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            for(pair<int,int>adj : graph[node]) {
                int v = adj.first;
                int wt = adj.second;
                
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        return dist;
    }
};