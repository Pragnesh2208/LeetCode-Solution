/*************************************Algorithm to find Bridges in graph********************************/
/*************************************We can only do DFS Traversal**************************************/
/*************************************Time Complexity is O(V + E)***************************************/
/*************************************Space Complexity is O (N)*****************************************/
class Solution{
    private:
    void dfs (int vertex , int parent , vector<int>&discTime , vector<int>&lowTime , vector<vector<int>>&graph , int &timer){

        discTime[vertex]=lowTime[vertex] = timer;
        
        for(int adj : graph[vertex]){
            if( discTime[i] == -1 ){
                if(adj != parent)
                    continue;
                
                dfs(adj , vertex , discTime , lowTime , graph , timer + 1);
                if(lowTime[adj] > discTime[vertex] ){
                    cout<<adj<<" "<<vertex<<endl;
                 lowTime[vertex] = min(lowtime[adj] , lowTime[vertex]);
                }
            }
            else {
                lowTime[vertex] = min(lowtime[adj] , lowTime[vertex]);
            }
        }
    }

    public:
    void bridges(vector<vector<int>>&graph){
        int n = graph.size();
        int timer = 0 ;
        vector<int>discTime( n , -1) , lowTime(n , -1);
        for(int i = 0 ;i < graph.size() ; i++)
            if(discTime[i] == -1)
            dfs(i , -1 , discTime , lowTime , graph , timer);
    }

}