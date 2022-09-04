/******************Check if Eulerian Path Does exist in Undirected Graph or Not***************/
/******************Time Complexity = O(V + E)***********************************************/
/******************Space Complexity = O(v)**************************************************/
class Solution{
    private:
    bool dfs(int vertex , vector<vector<int>>&graph , vector<bool> visit){

            visit[vertex] = true;
            
            for(auto i : graph[vertex])
            if(visit[i] == false)
            dfs(i , graph , visit);

    }
    bool isConnected(vector<vector<int>>&graph){
        int vertex = 0;
        for(vertex ; vertex < graph.size() ; vertex++ )
            if(graph[i].size() !=0 )break;
        
        if(vertex == graph.size())
        return true;
        int n = graph.size();

        vector<bool>visit( n , false );
        dfs(vertex , graph , visit);

        for(int i = 0 ;  i < n ; i++ ){
            if(graph[i].size() != 0 && visit[i] == false)
            return false;
        }
        return true;

    }
    void isEulerian(vector<vector<int>>&graph){

        if(isConnected(graph) == false)
        cout<<"This graph is not eulerian Path"<<endl;

        int n = graph.size();

        int odd = 0;
        int start = 0 , end =0;
        for(int i = 0 ; i < n ; i++ ){
            if( graph[i].size() % n != 0) odd++;
            
        }
        if(odd == 0)
        cout<<"This graph is eulerian circuit"<<endl;
        else if(odd == 2)
        cout<<"This graph is semi eulerian circuit or eulerian path"<<endl;
        else
        cout<<"This is graph is not eulerian circuit"<<endl;

    }
    public:
    void EulerianPath(vecto<vector<int>>&graph){
        
        isEulerian(graph);
    }
};