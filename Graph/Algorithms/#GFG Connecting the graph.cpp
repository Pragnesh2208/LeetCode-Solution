/**
 * Optimal Approach to Solve Connect the Graph
 * Time Complexity = O(m  + n)
 * where m is total edge , n is vertices.
 * Space Complexity = O(n);
 */
class DisJointSetByRank {

    public : 
    vector<int>parent , rank;
    public : 
    DisJointSetByRank(int n) {
        parent.resize(n + 1);
        rank.resize( n + 1, 1);
        for(int i = 0 ; i <= n ; i++) parent[i] = i ;
    }
    
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    bool areConnected(int u , int v) {
        return findParent(u) == findParent(v);
    }
    
    void unionByRank(int u , int v) {
        u = findParent(u);
        v = findParent(v);
        if(areConnected( u , v)) return;
        if(rank[u] > rank[v]) {
            parent[v] = u;
        } else if(rank[u] < rank[v]) {
            parent[u] = v;
        } else  {
            parent[u] = v;
            rank[v]++;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        DisJointSetByRank dsu(n);
        int numberOfComponents = 0;
        int extraEdge = 0;
        for(vector<int> edge : edges) {
            int u = edge[0] , v = edge[1];
            if(dsu.areConnected(u , v)) {
                extraEdge++;
                continue;
            }
            dsu.unionByRank(u,v);
        }
        
        for(int i = 0  ; i < n ; i++) {
            if(dsu.findParent(i) == i) numberOfComponents++;    
        }
        if(numberOfComponents - 1> extraEdge ) return -1;
        return numberOfComponents == 0 ? 0 : numberOfComponents - 1;
    }
};