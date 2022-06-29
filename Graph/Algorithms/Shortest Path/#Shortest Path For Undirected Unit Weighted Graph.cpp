
/*****************************Find Sortest Path for Undirected weighted graph*********/
/*****************************here distance between two vertices in 1*****************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/


class solutions
{
private:
    
public:
    vector<int> sortestPath(int V, int src, vector<int, int> adj[] , int src)
    {
        vector<bool> vis(V, false);
        queue<int>que;
        que.push_back(src);
        vector<int>dist(V , INT_MAX);
        dist[src] = 0;

        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(auto i : adj[node]) {
                if(dist[node] + 1 < dist[i]) 
                    dist[i] = dist[node]  +1;
                    que.push(i);
            }
        }
    return dist;
    }
};