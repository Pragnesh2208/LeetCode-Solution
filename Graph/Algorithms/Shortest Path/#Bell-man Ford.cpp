/*****************************Sortest Path Of Undirected/Directed weighted graph using BellMan-Ford*******/
/*****************************Here we are relaxing every edge by (total vertex - 1) **********************
*****************************So our time complexity is O(V * E)*******************************************/
/***************************Our Space Complexity is O(v)*************************************************/

/***************************Space Complexity = O(N) as we are using Priority queue and at Max we will store N vertices********/
class Solution{
    public:
    void Bell_man_ford(int vertex , vector<vector<int>>&graph ,int source ){
        int n = graph.size();
        vector<int>dist(vertex , INT_MAX);
        dist[source] = 0;

        for(int i = 1 ; i <= vertex   ; i++){
            for(int  i = 0 ; i < n ; i++ ){
                int u = graph[i][0];
                int v = graph[i][1];
                int weight = graph[i][2];
                if( dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
            }
        }
        //CHECK FOR NEGATIVE CYCLE
         for(int  i = 0 ; i < n ; i++ ){
                int u = graph[i][0];
                int v = graph[i][1];
                int weight = graph[i][2];
                if( dist[u] + weight < dist[v]){
                    cout<<"NEGATIVE CYCLE DETECTED"<<endl;
                    return;
                }   
            }
        for(int i = 0 ; i < n ; i++){
            cout<<dist[i]<<" ";
        }
    }
}