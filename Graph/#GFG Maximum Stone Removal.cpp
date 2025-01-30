/**
 * Optimal Solution for maximum stone removal
 * Time Complexity = O(N + totalCol + totalRow)
 * Space Complexity = O(N)
 */

class DSU{
    public:
    unordered_map<int,int>parent;
   public:
   DSU(vector<vector<int>>&stones) {
       for(vector<int>stone : stones) {
           int row = -(stone[0] + 1);
           int col = (stone[1] + 1);
           parent[row] = row;
           parent[col] = col;
       }
   }
    bool areConnected(int u , int v) {
        return findParent(u) == findParent(v);
    }
    int findParent(int node) {
        return parent[node] = node == parent[node] ? node : findParent(parent[node]);
    }
    
    int getCount() {
        int count = 0;
        for(pair<int,int> node : parent) {
            if(node.first == node.second) count++;
        }
        return count;
    }
    
    void unionBySize(int u , int v) {
        if(areConnected(u,v)) return;
        u = findParent(u);
        v = findParent(v);
        parent[v] = u;
        return ;
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        DSU dsu(stones);
        for(vector<int>stone : stones) {
            int row = -(stone[0] + 1);
            int col = stone[1] + 1;
            dsu.unionBySize(row , col);
        }
        
        return n - dsu.getCount();
    }
};