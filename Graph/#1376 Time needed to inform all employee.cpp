class Solution {
     unordered_map<int , vector<int>>graph;
        int mx = 0 , ans = 0;
    
    void dfs(int headID , vector<int>&informTime){
        
        mx = max(ans , mx);
        
        for(auto i : graph[headID]){
            ans += informTime[headID];
            
            dfs(i , informTime);
            
            ans -= informTime[headID];
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0 ; i < n; i++){
            if(manager[i] != -1)
            graph[manager[i]].push_back(i);
        }
        dfs(headID , informTime);
       
        return mx;
    }
};