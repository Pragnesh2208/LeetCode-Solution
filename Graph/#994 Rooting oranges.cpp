/*****************************Optimal solution of Rooting oranges**********************************/
/****************************Time Complexity = O( V + E)*******************************************/
/***************************Space Complexity = O(V + E) as we are using  que***********************/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>>que;
        int count = 0;
        vector<vector<bool>>visit(row, vector<bool>(col , false));
        for(int i= 0 ; i < row ; i++) {
            for(int j= 0 ; j < col ; j++){
                if(grid[i][j] == 2)
                    que.push({i , j});
            }
        }
        while(!que.empty()) {
            int size = que.size();
            bool flag = false;
            for(int x = 0  ; x < size ; x++){
               int i = que.front().first;
            int j = que.front().second;
       
            
            que.pop();
           
            if(i -1 >=0 && i -1 < row && grid[i-1][j] == 1 && visit[i-1][j] == false){
                que.push({i -1, j});
                flag = true;
                visit[i - 1][j] = true;
            }
            if(i + 1 >= 0 && i + 1 < row && grid[i+1][j] == 1 && visit[i+1][j] == false){
                 que.push({i + 1, j});
                visit[i + 1][j] = true;
                flag = true;
            }
            if(j -1 >=0 && j -1 < col && grid[i][j - 1] == 1 && visit[i][j - 1] == false){
                que.push({i, j - 1} );
                visit[i][j - 1] = true;
                flag = true;
            }
        if(j + 1 >= 0 && j + 1 < col && grid[i][j + 1] == 1 && visit[i][j + 1] == false){
                que.push({i, j + 1});
                visit[i][j + 1] = true;
                flag = true;
            } 
            }
            if(flag) count++;
            
           
        }
        
        for(int i = 0 ; i < row; i++)
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j]== 1 && visit[i][j] == false) {
                    count = -1;
                    break;
                }
            }
        return count;
    }
};