/*****************************BFS of Graph*********************************************/
/****************************Time Complexity = O( V + E)*******************************/
/***************************Space Complexity = O(V) as we are using visit array********/
  class solutions {
      bool visited[V]={false};
       queue<int>q;
       vector<int>v;
       q.push(0);
       visited[0]=true;
       while(!q.empty()){
           int temp = q.front();
           v.push_back(temp);
           q.pop();
           for(auto nbr:adj[temp]){
               if(!visited[nbr]) q.push(nbr);
               visited[nbr]=true;
           }
           
       }
       return v;
  }