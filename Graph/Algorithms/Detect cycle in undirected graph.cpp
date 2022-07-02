/*****************************Cycle Detection in undirected graph using BFS*********/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/


class solutions
{
private:
    
public:
    bool Iscycle(vector<int>graph[]){
        queue<pair<int,int>>que;//pair of node ,parent
        que.push(0 , -1);
        int n = graph.size();
        vector<bool> visit(n , false);
        visit[0]=true;
       while(!que.empty){
            int node = que.top().first;
            int parent = que.top().second;
            for(vector<int>::iterator itr = graph[node].begin() ; itr != graph[node].end() ; itr++ ){
                if(visit[*itr] == false){
                    que.push(*itr , node);
                    visit[*itr] = true;
                }
                else if(*itr != parent)
                return true;
            } 

       }
       return false;
    }
};

/*****************************Cycle Detection in undirected graph using DFS*********/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/


class solutions
{
private:
    bool dfs(int index , int parent , vector<bool>&visit , vector<int>&graph[]){
        if(index == graph.size()){
            return false;
        }
        visit[index] =true;
        for(vector<int>::iterator itr = graph[ind].begin() ; itr != graph.end() ; itr++) {
            if(visit[*itr] == false && dfs(*itr,node , visit , graph))
            return true;
            else if(*itr != parent)
            return true;
        }

    }
public:
    bool Iscycle(vector<int>graph[]){
        //pair of node ,parent
        
        
        vector<bool> visit(n , false);
        visit[0]=true;
        int n = graph.size();
        for(int i = 0 ; i < n ; i++){
            if(visit[i] == false){
                dfs( i ,-1, visit,graph);
            }
        }
       }
       return false;
    }
};