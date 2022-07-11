/*****************************Optimal solution of Number of Provinces*************************/
/****************************Time Complexity = O( V + E)**************************************/
/***************************Space Complexity = O(N) as we are using  Disjoint set*************/
class Disjoint_set {
    vector<int> parent, rank;
public:
    Disjoint_set(int n)  {
        parent.resize(n+1) ;
        rank.resize(n+1);
       for(int i = 0; i <= n ; i++){
           parent[i] = i;
           rank[i] = 0;
       }
    }
    int find(int x) {
        if(x == parent[x]) return x;                       
        return parent[x] = find(parent[x]);                  
    }
    bool Union(int x, int y) {
        int xp = find(x), yp = find(y);                 
        if(xp == yp) return false;                      
        if(rank[xp] > rank[yp]) parent[yp] = parent[xp];      
        else if(rank[yp] > rank[xp]) parent[xp] = parent[yp];
        else parent[xp] = yp, rank[yp]++;   
        return true;
    
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint_set object(n);
        vector<int>ans;
        for(auto &e : edges){
           if(! object.Union(e[0] , e[1])) {
               ans.push_back(e[0]);
               ans.push_back(e[1]);
               break;
           }
        }
        return ans;
    }
};