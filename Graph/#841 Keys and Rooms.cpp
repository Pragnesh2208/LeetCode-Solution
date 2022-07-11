/*****************************Optimal solution of Find Keys and Rooms******************************/
/****************************Time Complexity = O( V + E)*******************************************/
/***************************Space Complexity = O(N) as we are using  array vertices****************/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visit(n , false);
        
        queue<int>que;
        que.push(0);
        while(!que.empty()){
            int node = que.front();
            que.pop();
            visit[node] = true;
            for(int i : rooms[node])
                if(visit[i] == false){
                    que.push(i);
                }
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++) if(visit[i] == false) count++;
        return count==0;
    }
};