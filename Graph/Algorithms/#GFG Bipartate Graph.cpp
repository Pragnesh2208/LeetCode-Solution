/************************Method - 1 using BFS******************************************/
/*****************************Bipartate Graph using BFS********************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/
class Solution {
   void bfs(int node, vector<int>adj[] , vector<bool>&vis , vector<int>&color) {

        queue<int>que;
	    que.push(node);
	    color[node] = 0;
	    vis[node] =true;
	    while(!que.empty()) {
	        int temp = que.front();
	        que.pop();
	        for(auto i : adj[temp]) {
	            if(vis[i] == false) {
	                vis[i] =true;
	                color[i] = 1 - color[temp] ;
	                que.push(i);
	            }
	            else {
	                if(color[i] == color[temp]) return false;
	            }
	        }
	    }
	    
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<bool>vis(V , false);
	    vector<int>color(V ,-1);
	    
	    for(int j = 0 ; j < V ; j++) {
	        if(vis[j] == false){
	            bfs(j , adj , vis , color);
	        }
	    }
	    return true;
	}
};
/************************Method - 2 using DFS******************************************/
/*****************************Bipartate Graph using DFS********************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using color array********/

class Solution {
    bool dfs(int node  , vector<int>&color , vector<int>adj[] ) {
        if(color[node] == -1) color[node] = 0;
	     
        for(auto i : adj[node]) {
            if(color[i] ==-1) {
                color[i] = 1- color[node];
          
                if(!dfs(i, color , adj )) return false;
            }
            else  if(color[i] == color[node]) return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	   
	    vector<int>color(V,-1);
	    for(int i = 0 ; i < V; i++) {
	        if(color[i]==-1) {
	           
	            if(!dfs(i ,color , adj )) return false;
	           
	        }
	    }
	    return true;
	}

};
