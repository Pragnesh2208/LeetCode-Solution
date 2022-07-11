/*******************Kruskal's Algorthms to find MST ****************************************/
/*******************Time Complexity is O(E Log E)***************************************/
/*******************Space Complexity is O (N)***********************************************/
class comparator{
    private:
    int weight , source , destination;
    private:
    bool cmp(comparator c1 , comparator c2){
        return c1.weight < c2.weight;
    }
    friend class Solution;
};
class Solution{
    private:
    vector<int>rank(100000 , 0);
    vector<int>parent(100000);

    void make_set(int n){
        for(int i = 0 ; i <=n ; i++)
            parent[i]=i;
    }
    int find(int node){
        if(node == parent[node]) return node;
        else  return parent[node] = find(parent(node));
    }
    void union(int node1 , int node2){
        int node1 = find(node1);
        int node2 = find(node2);

        if(rank[node1] > rank[node2]) 
            parent[node2] = node1;
        else if(rank[node1] < rank[node2])
             parent[node1] = node2;
        else {
            parent[node2] = node1;
            rank[node1]++;
        }
    }
    
    public:
    kruskal(vector<vector<int>>&graph){
        vector<pair<int , int>>mst;
        sort(graph.begin() , graph.end() , cmp);
        int n = graph.size();
        for(int i = 0 ; i < n ; i++){
            if(find(graph[i][1] ) != find(graph[i][2] )){

                union(graph[i][1] , graph[i][2]);

                weight += graph[i][0];

                mst.push_back(graph[i][1] , graph[i][2]);
            }
        }
        for(auto i : mst)
        cout<<i.first<<" "<<i.second<<endl;
    }
}