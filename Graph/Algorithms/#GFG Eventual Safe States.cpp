
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




/*****************************Detect Cycle in Directed Graph Using BFS Topo sort****************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V+E) as we are creating new graph********/

class Solution {

  public:
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        // code here
        vector<vector<int>>adj(V);
        for(int node = 0 ; node < V ; node++) {
            for(int child : graph[node]) {
                adj[child].push_back(node);        
            }
        }
        
        vector<int>safeNodes;
        vector<int>indegree(V , 0);
        for(int node = 0 ; node < V ; node++) {
            for(int child : adj[node]) {
                indegree[child]++;
            }
        }
        
        queue<int>que;
        for(int node  = 0 ; node < V ; node++) if(indegree[node] == 0) que.push(node);
        vector<bool>isSafe(V , false);
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            isSafe[node] = true;
            
            for(int child : adj[node]) {
                indegree[child]--;
                
                if(indegree[child] == 0) que.push(child);
            }
        }
        
        for(int node = 0; node < V ; node++) if(isSafe[node])safeNodes.push_back(node);
        
        return safeNodes;
    }
};