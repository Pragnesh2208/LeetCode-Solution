/******************************Method 1 Using DFS*/
/*****************************Topological sort usign dfs*******************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/
class Solution
{
    vector<int>ans;
    void dfs(int node  , vector<int>adj[] , vector<bool>&vis , stack<int>&st) {
        vis[node] = true;
        
        for(auto i : adj[node]) {
            if(vis[i] == false){ 
                
                dfs(i , adj , vis , st);
        	}
		}
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V , false);
	    stack<int>st;
	    for(int i = 0 ; i < V ; i++) {
	        if(vis[i] == false)
	        dfs(i , adj , vis ,st );
	    }
	    while(!st.empty()) {
	        int a = st.top();
	        st.pop();
	        ans.push_back(a);
	    }
	    return ans;
	}
};

/******************************Method 2 Using BFS**************************************/
/*****************************Topological sort usign bfs or Kahn's algorithm*******************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int>inorder(v , 0);
	    for(int i = 0 ; i < v ;i++) {
	        for(auto j : adj[i])
	        inorder[j]++;
	    }
	    
	    queue<int>que;
	    vector<int>ans;
	    for(int i = 0 ; i < v ; i++) 
	        if(inorder[i] == 0) que.push(i);
	    
	    while(!que.empty()) {
	        int x = que.front();
	        que.pop();
	        ans.push_back(x);
	        for(auto i : adj[x]) {
	            inorder[i]--;
	            if(inorder[i] == 0) que.push(i);
	        }

	    }
	    return ans;
	    
	}
};



