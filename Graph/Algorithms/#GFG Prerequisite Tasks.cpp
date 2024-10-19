
/*****************************Optimal Solution to solve Prerequisite Task****************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	   vector<vector<int>>graph(N);
	   
	   for(pair<int,int> pre : prerequisites) {
	       int parentNode = pre.second;
	       int childNode = pre.first;
	       graph[parentNode].push_back(childNode);
	   }
	   vector<int>indegree(N , 0);
	   
	   for(int node = 0 ; node < N ; node++) {
	       for(int childNode : graph[node]) {
	           indegree[childNode]++;
	       }
	   }
	   
	   queue<int>que;
	   for(int node = 0 ; node < N ; node++) if(indegree[node] == 0) que.push(node);
	   vector<int>topo;
	   while(!que.empty()) {
	       int node = que.front();
	       que.pop();
	       topo.push_back(node);
	       
	       for(int child : graph[node]) {
	           indegree[child]--;
	           if(indegree[child] == 0) que.push(child);
	       }
	   }
	   
	   return topo.size() == N;
	   
	}
};