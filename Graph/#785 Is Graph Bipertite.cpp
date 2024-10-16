/**
 * Optimised solution using bfs to check is Graph Bipertite
 * Time complexity = O(M*N)
 * Space Complexity = O(M*N)
 */
class Solution {
    private:
    bool bfs(int node , vector<vector<int>>&graph , vector<pair<bool,int>>&visited , int prevColor) {
        bool nodeVisited = visited[node].first;
        int nodeColor = visited[node].second;
        if(nodeVisited) return prevColor != nodeColor;
        int currentColor =  prevColor == -1 ? 1 : prevColor == 1 ? 2 : 1;

        visited[node] = make_pair(true ,currentColor);
        for(int connectedNode : graph[node]) {
            if(!bfs(connectedNode , graph , visited ,currentColor )) return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int totalNodes = graph.size();
        vector<pair<bool , int>>visited(totalNodes , make_pair(false , -1));

        for(int node = 0 ; node < totalNodes ; node++) {
            if(!visited[node].first && !bfs(node , graph , visited , -1)) return false ;
        }
        return true;
    }
};


/**
 * Optimised solution using dfs to check is Graph Bipertite
 * Time complexity = O(M*N)
 * Space Complexity = O(M*N)
 */
class Solution {
    private:
    bool dfs(int node , vector<vector<int>>&graph , vector<pair<bool,int>>&visited ) {  
        queue<pair<int , int>>que;
        que.push({node , 1});
        visited[node] = make_pair(true ,1);
        while(!que.empty()) {
            int sz = que.size();
            while(sz--) {
                pair<int,int> frontNode = que.front();
                que.pop();
                int node = frontNode.first;
                int nodeColor = frontNode.second;

                for(int connectedNode : graph[node]) {
                    pair<bool,int>connectedNodeInfo = visited[connectedNode];
                    bool connectedNodeVisited = connectedNodeInfo.first;
                    int connectedNodeColor = connectedNodeInfo.second;

                    if(connectedNodeVisited) {
                        if(connectedNodeColor == nodeColor) return false;
                    } else {
                        int currentColor =  nodeColor ==  1  ? 2 : 1;
                        que.push({connectedNode , currentColor});
                        visited[connectedNode] = {true , currentColor};
                    }
                }
            }
        }
        

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int totalNodes = graph.size();
        vector<pair<bool , int>>visited(totalNodes , make_pair(false , -1));

        for(int node = 0 ; node < totalNodes ; node++) {
            if(!visited[node].first && !dfs(node , graph , visited )) return false ;
        }
        return true;
    }
};