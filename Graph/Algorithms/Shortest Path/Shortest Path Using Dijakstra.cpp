/*****************************Sortest Path Of Undirected/Directed weighted graph using Dijakstra Algorithm*******/
/****here we are visiting every vertices so for wrost case our time complexity for visiting every vertices is O(N + E)
 And we also use Priority queue and at Max we can add N vertices so for that our time complexity will be O(N+E) * Log(N)***********/

/***************************Space Complexity = O(N) as we are using Priority queue and at Max we will store N vertices********/

Class Solution{
    public:
    vector<int,int>  Dijakstra(vector<pair < int,int> > graph ,int source ){
        int vertices = graph.size();
        vector<int,int>dist(vertices , INT_MAX);
        dist[source] = 0;

        priority_queue<pair<int , int>  , vector<pair<int,int>>, greater<pair<int , int >>> minheap;
        minheap.push(0 , source);
        while (!minheap.empty())
        {
            int weight = minheap.top().second;
            int vertice = minheap.top().first;
            minheap.pop();
            for(vector<pair<int , int >>::iterator i = graph[vertice].begin() ; i != graph[vertice].end() ; i++ ){
                int weightOfvertice = i -> second;
                int node = i > first;
                if(dist[node] > dist[vertice] + weightOfvertice){
                    dist[node] = dist[vertice] + weightOfvertice;
                    minheap.push( make_pair(node, dist[node])  );
                }
            }
        }
        

    }
}