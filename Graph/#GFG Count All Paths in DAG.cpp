/*****************************Optimal solution of Find Count All Paths in DAG**********************************/
/*****************************Time Complexity = O( V + E)******************************************************/
/*****************************Space Complexity = O(N) as we are using  array of dfsvis*************************/
class Solution {
    void dfs(int vertex , vector<vector<int>>&graph , vector<bool>&dfsvis , int &ans, int &d){
        if(vertex == d){
            ans+=1;
           
            return;
        }
        
        dfsvis[vertex] = true;
        
        for(int adjacent : graph[vertex]){
            
            if(dfsvis[adjacent] == false) {
                dfs(adjacent , graph , dfsvis , ans , d);
            }
        }
        dfsvis[vertex] = false;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<vector<int>>graph(n , vector<int>());
	    
	    for(int i = 0 ; i < edges.size() ; i++){
	        int u  = edges[i][0];
	        int v = edges[i][1];
	        
	        graph[u].push_back(v);
	    }
	    int ans = 0;
	
	    vector<bool>dfsvis(n , false);
	   
	        dfs(s , graph,dfsvis ,ans, d);    
	    
	    return ans;
	}
};
