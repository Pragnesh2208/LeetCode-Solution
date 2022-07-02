class Solution{
    private:
    vector<int>parent(100000,0);
    vector<int>parent(100000,0);

    void make_set(){
        for(int i = 0 ; i <= n ; i++)
        parent[i]=i;
    }

    void union(int i , int j){
        int i = find(i);
        int j = find(j);

        if(rank[i] > rank[j]){
            parent[j] = i;
        }
        else if(rank[i] < rank[j]){
            parent[i] = j;
        }
        else{
            parent[i] = j;
            rank[j]++;
        }
    }

    int find(int i){
        if(parent[i]==i)
            return i;
        //return parent[i]=find(parent[i]);//compression method
        return find(parent[i]);
    }    
};