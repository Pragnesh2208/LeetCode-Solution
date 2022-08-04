/*****************************Optimal solution of Find Eventual safe states*************************/
/****************************Time Complexity = O( V + E)**************************************/
/***************************Space Complexity = O(N) as we are using  visit and safe*************/
class Solution {
    private:
    bool dfs(int &vertex , vector<bool>&visit , vector<vector<int>>&graph , vector<bool>&safe) {
        if(graph[vertex].size() == 0) {
            return true;
        }
        visit[vertex] = true;
        int count = 0;
        for(auto i : graph[vertex]) {
            if(visit[i] == false)
                safe[i] = dfs(i , visit , graph , safe);
            if(safe[i] == true)
                count++;
        }
        return count == graph[vertex].size();
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int vertex = graph.size();
        vector<bool>safe(vertex , false);
        vector<bool>visit( vertex , false);
        for(int i = 0 ; i < vertex ; i++ ){
            if(visit[i] == false) {
               safe[i]= dfs(i , visit , graph , safe); 
                
            }
            if(safe[i] == true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};