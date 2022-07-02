/***************************Method - 1 By creating the Adjencency List of Graph using Unorder_map*************/
/*****************************Find if path exists in Graph using graph****************************************/
/****************************Time Complexity = O( V + E)******************************************************/
/***************************Space Complexity = O(V) as we are using visit array*******************************/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
       if(source == destination) return true;
       
        //Creating the adjencency list of Graph
        unordered_map<int , vector<int>> graph(n);
        int N = edges.size();
        for(int i = 0 ; i < N ; i++) {
            
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            
        }
      vector<bool>visit(n , false);
        queue<int>que;
        visit[source] = true;
       for(auto i : graph[source]) { 
           visit[i] = true;
           if(i == destination) 
               return true;
           que.push(i); 
       }

        while(!que.empty()) {
            
            int node = que.front();
            que.pop();
            visit[node] = true;
            for(int i : graph[node]) {
                if(visit[i] == false){
                    if(i == destination) return true;
                    else 
                        que.push(i);
                }
            }
        }
         return false;
    }
};

/***************************Method - 1 By creating the Adjencency List of Graph using 2D vector*************/
/*****************************Find if path exists in Graph using graph****************************************/
/****************************Time Complexity = O( V + E)******************************************************/
/***************************Space Complexity = O(V) as we are using visit array*******************************/


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
       if(source == destination) return true;
        vector<vector<int>> graph(n ,vector<int>());
        int N = edges.size();
        for(int i = 0 ; i < N ; i++) {
            
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            
        }
      vector<bool>visit(n , false);
        queue<int>que;
        visit[source] = true;
       for(int i = 0 ;i < graph[source].size() ; i++) { 
           visit[graph[source][i]] = true;
           if(graph[source][i] == destination) 
               return true;
           que.push(graph[source][i]); 
       }
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            visit[node] = true;
            for(int i = 0 ; i < graph[node].size() ; i++) {
                if(visit[graph[node][i]] == false){
                    if(graph[node][i] == destination) return true;
                    else 
                        que.push(graph[node][i]);
                }
            }
        }
         return false;
    }
};