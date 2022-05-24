
/*****************************DFS of Graph*********************************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/
class Solution {
    private:
    void dfs( int node , vector<int> adj[] , vector<bool>&visit , vector<int>&ans ) {
        
        if(visit[node] == false){
        visit[node] = true;
        ans.push_back(node);}
        
        for(auto i : adj[node]) {
            if(visit[i] == false){
            ans.push_back(i);
            visit[i] = true;
            dfs( i , adj , visit , ans);}
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool> visit(V , false);
        for(int i = 0 ; i < V ;i++) {
            if(visit[i] == false)
                dfs(i , adj , visit , ans);
        }
        return ans;
    }
};
