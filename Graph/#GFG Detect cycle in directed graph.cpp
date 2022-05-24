
/*****************************Detect Cycle in Directed Graph****************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/
class Solution {
    private:
    bool dfs(int node , vector<int>adj[] , vector<bool>&visit , vector<bool>& dfsVis) {
        if(visit[node] == false ) {
            visit[node] = true;
            dfsVis[node] = true;
        for(auto i : adj[node]) {
                
                if(visit[i] == false && dfs(i ,adj , visit, dfsVis) == true) return true;
                else if(dfsVis[i] == true) return true;
        
          }
          dfsVis[node] = false;
          return false;
       }
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
      vector<bool> visit(V , false);
      vector<bool>dfsVis(V  , false);
      
      for(int i = 0 ; i  <V ; i++) {
          if(visit[i] == false) {
              if(dfs( i , adj , visit , dfsVis)) return true;
          }

          }
      return false;
    }
};