
/*****************************Detect Cycle in Directed Graph****************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/

class Solution {

  private:
  bool dfs(int node , vector<bool>&visited , vector<bool>&path , vector<int>adj[] , vector<bool>&check) {
        if(visited[node]) return path[node];
        
        visited[node] = true;
        path[node] = true;
        check[node]=false;
        for(auto newNode : adj[node]) {
            if(dfs(newNode , visited, path , adj , check)) return true;
        }
        check[node] = true;
        path[node] = false;
        return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V , false);
        
        vector<bool>check(V , false);
        vector<int>ans;
        vector<bool>path(V , false);
        for(int node = 0 ; node < V ; node++) {
            
            if(!visited[node]) 
                dfs(node , visited , path , adj , check);
        }
        
        for(int node = 0 ; node < V ; node++) {
            if(check[node])
            ans.push_back(node);
        }
        
        return ans;
    }
};