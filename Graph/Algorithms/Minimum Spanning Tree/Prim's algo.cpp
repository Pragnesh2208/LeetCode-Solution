/*******************Prim's Algorthms to find MST in graph Using Brute Force Approach*************/
/*******************Time Complexity is O(N ^ 2)**************************************************/
/*******************Space Complexity is O (N)****************************************************/
class Solution
{
private:
    /* data */
public:
    void prims(vector<pair<int,int>> graph){
        int n = graph.size();
        vector<bool>mst( n ,false);
        vector<int>value (n ,INT_MAX);
        vector<int>parent(n , -1);
        value[0] = 0;
        mst[0]=true;
        // As to connect n nodes in mst only n-1 edge are required
        for(int count = 0 ; count < n - 1 ; count++ ){
                int min = INT_MAX , u;
                for(int i = 0; i < n ;i++){
                    if(mst[i] == false && value[i]  < min) {
                        min = value[i];
                        u = i;
                    }
                }
 mst[u]=true;
                for(pair<int,int> adj : graph[u] ){
                    int v = adj.first;
                    int weight = adj.second;
                    
                    if(mst[v] == false && value[v] > weight){
                        value[v] =weight;
                        parent[v]=u;
                    }
                }
                for(int i = 0; i < n ; i++){
                    cout<<parent[i]<<" ";
                }
                cout<<endl;
        }
    }
};


/*******************Prim's Algorthms to find MST in graph Using minheap Optimal Approach*************/
/*******************Time Complexity is O(N + E Log N)**************************************************/
/*******************Space Complexity is O (N)****************************************************/
class Solution
{
private:
    /* data */
public:
    void prims(vector<pair<int,int>> graph){
        int n = graph.size();
        vector<bool>mst( n ,false);
        vector<int>parent value(n , -1);
        priority_queue<pair<int,int> , vector<pair<int,int>>  , greater<pair<int,int>>> pq;
        pq.push{0 ,0 };
        value[0]=0;
        mst[0]=true;
        // As to connect n nodes in mst only n-1 edge are required
        for(int count = 0 ; count < n - 1 ; count++ ){
                    int u = pq.top().first;
                    pq.pop();
                    mst[u]=true;

                for(pair<int,int> adj : graph[u] ){
                    int v = adj.first;
                    int weight = adj.second;
                    
                    if(mst[v] == false && value[v] > weight){
                        pq.push(v , weight);
                        parent[v]=u;
                        value[v] = weight;
                    }
                }
                for(int i = 0; i < n ; i++){
                    cout<<parent[i]<<" ";
                }
                cout<<endl;
        }
    }
};








