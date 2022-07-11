/*************************************Tarjan's Algorithm to find articulation points in graph***********/
/*************************************We can only do DFS Traversal**************************************/
/*************************************Time Complexity is O(V + E)***************************************/
/*************************************Space Complexity is O (N)*****************************************/
class Solution{
    private:
    void dfs(int vertex , int parent , int &timer , vector<int>&DiscTime , vector<int>&lowTime , vector<bool>&articulation , vector<vector<int>>&graph){

        DiscTime[vertex] = lowTime[vertex] = timer;
        timer++;
        int child = 0;
        for(int adj : graph[vertex]){

            if(adj == parent) 
                continue;
            
            if(DiscTime[adj]== -1){
                child++;
                
                dfs(adj , vertex , timer , DiscTime , lowTime  , articulation , graph);
             
                if(lowtime[adj] >= DiscTime[vertex] && parent != -1)
                    articulation[vertex] = true;
                    
                else{
                       lowTime[vertex] = min(lowTime[adj] , lowTime[vertex]);
                }
            }
            else{
                lowTime[vertex] = min(lowTime[adj] , lowTime[vertex]);
            }
        }
        if(parent == -1 && child >= 2)
            articulation[vertex] = true;

    }
    public:
    vector<int> ArticulationPoints(vector<vector<int>>&graph){
        int n = graph.size();
        vector<int>DiscTime(n , -1);
        vector<int>lowTime(n , -1);
        vector<bool>articulation(n , false);
        vector<int>ans;
        int timer = 0;

        for(int i = 0 ; i < n ; i++){

            if(DiscTime == -1){
                int vertex = i;
                dfs( i , -1 , timer,DiscTime , lowTime , articulation , graph);
            }
        }
       
        for(int i = 0 ; i < n ; i++)
            if(articulation[i] == true)
                ans.push_back(i);

        return ans;
    }
};