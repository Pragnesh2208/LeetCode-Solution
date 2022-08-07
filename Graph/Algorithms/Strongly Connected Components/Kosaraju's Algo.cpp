Class Solution{
    public:
    void dfs(int vertex , vector<vector<int>>&adj , vector<bool>&visit , stack<int>&st){
        visit[vertex] = true;
        for(auto i : adj[vertex])
            if(visit[i] == false)
            dfs(i , adj , visit , st);
        st.push(vertex);
    }
    void dfsUtil(int vertex , vector<vector<int>>&adj , vector<vector<int>>&newAdj , vecor<bool>&visit) {
        visit[vertex] = true;
        for(auto i : adj[vertex]){
            if(visit[i] == false){
                dfsUtil(i , adj , newAdj);
            }
            newAdj[i].push_back(vertex);
        }
    }
    void newDfs(int vertex , vector<vector<int>>&adj , vector<int>&newAdj , vecor<bool>&visit) {
        visit[vertex] = true;
        for(auto i : adj[vertex]){
            if(visit[i] == false){
                dfsUtil(i , adj , newAdj);
            }
            newAdj.push_back(i);
        }
    }
    void reverseGraph(vector<vector<int>>&adj , int &V , vector<vector<int>>&newGraph){
        vector<bool>visit(V , false);
        for(int i = 0 ; i < V ; i++) {
            if(visit[i] == false)
            dfsUtil(i , adj , newGraph , visit);
        }
    }
   
    public:
    vector<vector<int>> kosaRaju(vector<vector<int>>adj , int V) {
        vector<bool>visit(V , false);
        int ans = 0;
        stack<int>st;
        for(int i = 0 ; i < V ; i++){
            if(visit[V] == false)
            dfs( i , adj , visit , st);
        }
        vector<vector<int>> newGraph(V);

        reverseGraph(adj , V , newGraph);
        for(int i = 0 ; i < V ; i++){
            visit[i] = false;
        }
        vector<vector<int>>ans;
        while(!st.empty()){
            int vertex = st.top();
            if(visit[vertex] == false){
                vector<int>temp;
                newDfs(vertex , newGraph ,temp,visit);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};