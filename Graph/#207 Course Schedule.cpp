/*****************************Optimal solution of Course Schedule*****************************/
/****************************Time Complexity = O( V + E)**************************************/
/***************************Space Complexity = O(N) as we are using inorder*******************/

class Solution {
    private:
    void makeGraph( vector<vector<int>>&graph , int & numCourses ,vector<vector<int>>& prerequisites ){
        
        for(int i = 0 ; i < prerequisites.size() ; i++ ){
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            graph[src].push_back(dest);
        }
    }
    
    bool topoSort(queue<int>&que ,vector<vector<int>>&graph , vector<int>&inorder , int & numCourses){
        
        int count = 0;
        while(!que.empty()){
            count++;
            int vertex = que.front();
            que.pop();
            
            for(auto i : graph[vertex]){
                inorder[i]--;
                if(inorder[i] == 0)
                    que.push(i);
            }   
        }
        return count == numCourses;
    }
    
public:
    bool canFinish(int numCourses ,vector<vector<int>>& prerequisites ) {
    
        vector<int>inorder(numCourses , 0);
        vector<vector<int>>graph(numCourses);
         makeGraph(graph , numCourses , prerequisites);
        
        for(int i = 0 ; i < numCourses ; i++ )
            for(auto j : graph[i])
                inorder[j]++;
        queue<int>que;
        for(int i = 0 ; i  < numCourses ; i++)
            if(inorder[i] == 0)
                que.push(i);
       return topoSort(que , graph ,inorder , numCourses);
    }
};