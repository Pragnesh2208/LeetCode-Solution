/*****************************Find Sortest Path for DAG (Directed Acyclic weighted graph)*******/
/*****************************Topological sort usign dfs*******************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/

class solutions
{
private:
    void toposort(int node vector<bool> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = true;
        for (auto i : adj[node])
        {
            if (vis[i] == false)
                toposort(i, vis, st);
        }
        st.push(node);
    }
public:
    vector<int, int> sortestPath(int V, int src, vector<int, int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int, int> dist(V, INT_MAX);
        dist[src] = 0;
        stack<int> St;
        toposort(src, vis, st, adj);

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (dist[node] != INT_MAX)
            {
                for (auto i : node)
                {
                    if (dist[i] >= dist[i] + dist[node])
                        dist[i] = dist[i] + dist[node];
                }
            }
        }
    }
};
