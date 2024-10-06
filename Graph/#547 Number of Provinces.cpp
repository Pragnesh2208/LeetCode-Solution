/*****************************Optimal solution of Number of Provinces using DFS******************************/
/****************************Time Complexity = O( V * E) As we are using adjacent matrix***********/
/***************************Space Complexity = O(N) ******************/
class Solution {
void dfs(vector<vector<int>>&matrix , vector<bool>& visited , int vector) {
    if(visited[vector]) return;
    visited[vector] = true;
    int totalVector = matrix.size();
    for(int newVector = 0 ; newVector < totalVector ; newVector++ ) {
        if(matrix[vector][newVector])
        dfs(matrix , visited , newVector);
    }
    return;
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalVector = isConnected.size();
        vector<bool>visited(totalVector , false);
        int totalProvince = 0;
        for(int vector = 0 ; vector < totalVector ; vector++) {
            if(!visited[vector])
            {
                totalProvince++;
                dfs(isConnected , visited , vector);
            }
        }

        return totalProvince;
    }
};

/*****************************Optimal solution of Number of Provinces******************************/
/****************************Time Complexity = O( V * E) As we are using adjacent matrix***********/
/***************************Space Complexity = O(N) as we are using  Disjoint set******************/
class disjoint_set{
    private:
    vector<int>parent;
    vector<int>rank;
    
    disjoint_set(){
        parent.resize(201);
        rank.resize(201);
         for(int i = 0; i < 201 ; i++)
            parent[i]=i;
    }
    
    private:
 
    int find(int node){
        if(parent[node] == node) return node;
        else
            return parent[node] = find(parent[node]);
        
    }
    void uni(int node1 , int node2){
        node1 = find(node1);
        node2 = find(node2);
        if(node1 == node2)
            return;
        if(rank[node1] > rank[node2]){
            parent[node2] = node1;
            
        }
        else if(rank[node1] < rank[node2]){
            parent[node1] = node2;
        }
        else {
            parent[node2] = node1;
            rank[node1]++;
        }
    }
    int component(int n){
        int count = 0;
        for(int i = 0 ;i < n ; i++)
            if(parent[i] ==i)
                count++;
        return count;
    }
    friend class Solution;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        disjoint_set obj;
        int N = isConnected.size();
        int M = isConnected[0].size();
        for(int i = 0; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(isConnected[i][j] == 1)
                    obj.uni(i, j);
            }
        }
           
        return obj.component(N);
    }
};